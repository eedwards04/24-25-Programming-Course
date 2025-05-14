#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct Time {
    int h, m, s;
    int toSec() const {
        return h * 3600 + m * 60 + s;
    }
};

struct Racer {
    int id;
    Time start, mid, finish;
    bool hasStart = false, hasMid = false, hasFinish = false;
};

// Assumes time is in HH:MM:SS format
Time parseTime(const string& t) {
    Time time;
    stringstream ss(t);
    ss >> time.h >> time.m >> time.s;
    return time;
}

int diff(const Time& t1, const Time& t2) {
    return t2.toSec() - t1.toSec();
}

double pace(int seconds, double miles) {
    if (miles <= 0.0) return 0.0;
    return (seconds / 60.0) / miles;
}

int main() {
    ifstream file("race_log.txt");
    if (!file) {
        cerr << "Error: Could not open race_log.txt\n";
        return 1;
    }

    string line;
    map<int, Racer> racers;
    bool first = true;
    Time gunTime;

    while (getline(file, line)) {
        if (first) {
            gunTime = parseTime(line);
            first = false;
            continue;
        }

        stringstream ss(line);
        string sid, rid, tstr;
        getline(ss, sid, ',');
        getline(ss, rid, ',');
        getline(ss, tstr);

        try {
            int sensor = stoi(sid);
            int id = stoi(rid);
            Time t = parseTime(tstr);

            if (!racers.count(id)) racers[id] = Racer{id};

            if (sensor == 0) {
                racers[id].start = t;
                racers[id].hasStart = true;
            } else if (sensor == 1) {
                racers[id].mid = t;
                racers[id].hasMid = true;
            } else if (sensor == 2) {
                racers[id].finish = t;
                racers[id].hasFinish = true;
            }
        } catch (const exception& e) {
            cerr << "Skipping malformed line: " << line << " (" << e.what() << ")\n";
        }
    }

    // Output splits for all racers
    cout << "\nRacer Splits:\n";
    for (map<int, Racer>::iterator it = racers.begin(); it != racers.end(); ++it) {
        const int id = it->first;
        const Racer& r = it->second;

        if (!r.hasStart || !r.hasMid || !r.hasFinish) continue;

        int split1 = diff(r.start, r.mid);
        int split2 = diff(r.mid, r.finish);
        int total = diff(r.start, r.finish);

        double pace1 = pace(split1, 7.0);
        double pace2 = pace(split2, 6.1);
        double overallPace = pace(total, 13.1);

        cout << "\nRacer #" << id << ":\n";
        cout << "  Split 1 (start -> 7 mi):   " << split1 / 60 << " min " << split1 % 60 << " sec (" << pace1 << " min/mile)\n";
        cout << "  Split 2 (7 mi -> finish): " << split2 / 60 << " min " << split2 % 60 << " sec (" << pace2 << " min/mile)\n";
        cout << "  Total time:               " << total / 60 << " min " << total % 60 << " sec (" << overallPace << " min/mile)\n";
    }

    // Check for suspected cheaters
    cout << "\nSuspected Cheaters:\n";
    for (map<int, Racer>::iterator it = racers.begin(); it != racers.end(); ++it) {
        int id = it->first;
        Racer& r = it->second;
        bool cheater = false;
        cout << "\nRacer #" << id << ": ";

        if (!r.hasStart || !r.hasMid || !r.hasFinish) {
            cout << "Missed sensor(s).";
            cheater = true;
        } else {
            int split1 = diff(r.start, r.mid);
            int split2 = diff(r.mid, r.finish);
            double pace1 = pace(split1, 7.0);
            double pace2 = pace(split2, 6.1);

            if (pace1 < 4.5 || pace2 < 4.5) {
                cout << fixed << setprecision(2);
                cout << "Suspicious pace (Split1: " << pace1
                     << " min/mile, Split2: " << pace2 << " min/mile)\n";
                cheater = true;
            }
        }

        if (!cheater) continue;
        cout << endl;
    }

    return 0;
}
