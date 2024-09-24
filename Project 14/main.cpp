#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int exercise_amt;
    double exercise_score, score_possible, total_points_gained = 0, total_possible_points = 0;
    cout<<"How many exercises would you like to input? \n";
    cin>>exercise_amt;
    for(int i=0;i<exercise_amt;i++) {
        cout<<"How many possible points for this exercise: \n";
        cin>>score_possible;
        cout<<"Score received for this exercise: \n";
        cin>>exercise_score;
        total_points_gained = exercise_score + total_points_gained;
        total_possible_points = score_possible + total_possible_points;
    }
    const double total_score = (total_points_gained / total_possible_points) * 100;
    cout<<fixed<<setprecision(2);
    cout<<"Your total is "<<total_points_gained<<" out of "<<total_possible_points<<" or "<<total_score<<"%"<<endl;
    return 0;
}
