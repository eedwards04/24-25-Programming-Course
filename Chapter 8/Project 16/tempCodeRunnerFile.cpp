#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Time {
    int hour, minute, second;
    int toSeconds() const {
        return hour * 3600 + minute * 60 + second;
    }
};

struct Racer {
    int id;
    Time start, mid, finish;
    bool hasStart = false, hasMid = false, hasFinish = false;
};

Time parseTime(const string& tstr) {
    Time t;
    stringstream ss(tstr);
    ss >> t.hour >> t.minute >> t.second;
    return t;
}

int timeDiff(const Time& t1, const Time& t2) {
    return t2.toSeconds() - t1.toSeconds();
}

double pace(int seconds, double miles) {
    return (seconds / 60.0) / miles;
}

void printRacerStats(const Racer& r, const Time& gunTime, int place) {
    int totalSec = timeDiff(gunTime, r.finish);
    int split1 = timeDiff(r.start, r.mid);
    int split2 = timeDiff(r.mid, r.finish);
    double pace1 = pace(split1, 7.0);
    double pace2 = pace(split2, 6.1);
    double overallPace = pace(totalSec, 13.1);

    cout << "\nRacer #" << r.id << " - Finished in place #" << place << endl;
    cout << fixed << setprecision(2);
    cout << "Split 1 (Start to Mile 7): " << split1 / 60.0 << " minutes, Pace: " << pace1 << " min/mile\n";
    cout << "Split 2 (Mile 7 to Finish): " << split2 / 60.0 << " minutes, Pace: " << pace2 << " min/mile\n";
    cout << "Total Time: " << totalSec / 60.0 << " minutes, Overall Pace: " << overallPace << " min/mile\n";
}

int main() {
    ifstream infile("race_log.txt");
    string line, go_again;

    map<int, Racer> racers;
    Time gunTime;
    bool firstLine = true;
    do {
    while (getline(infile, line)) {
        if (firstLine) {
            gunTime = parseTime(line);
            firstLine = false;
            continue;
        }

        stringstream ss(line);
        string sensorStr, idStr, timeStr;
        getline(ss, sensorStr, ',');
        getline(ss, idStr, ',');
        getline(ss, timeStr);

        int sensor = stoi(sensorStr);
        int id = stoi(idStr);
        Time t = parseTime(timeStr);

        if (!racers.count(id)) {
            racers[id] = Racer{id};
        }

        if (sensor == 0) { racers[id].start = t; racers[id].hasStart = true; }
        else if (sensor == 1) { racers[id].mid = t; racers[id].hasMid = true; }
        else if (sensor == 2) { racers[id].finish = t; racers[id].hasFinish = true; }
    }

    // Determine places by sorting based on finish time
    vector<Racer> finished;
for (auto& racerPair : racers) {
    int id = racerPair.first;
    Racer& r = racerPair.second;
    if (r.hasStart && r.hasMid && r.hasFinish)
        finished.push_back(r);
}

sort(finished.begin(), finished.end(), [&](Racer a, Racer b) {
    return a.finish.toSeconds() < b.finish.toSeconds();
});

int racerNum;
cout << "Enter racer number to view stats: ";
cin >> racerNum;

auto it = find_if(finished.begin(), finished.end(), [=](const Racer& r) { return r.id == racerNum; });

if (it != finished.end()) {
    int place = distance(finished.begin(), it) + 1;
    printRacerStats(*it, gunTime, place);
} else {
    cout << "Racer not found or incomplete data.\n";
}
    cout << "go again?";
    cin >> go_again;
    } while (go_again == "Y" || go_again =="y");
    
    return 0;
}
