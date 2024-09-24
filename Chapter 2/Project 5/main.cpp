#include <iostream>
using namespace std;

int main() {
    int room_capacity, number_of_people;
    cout<<"What is the rooms total capacity?\n";
    cin>>room_capacity;
    cout<<"How many people are attending the meeting?\n";
    cin>>number_of_people;
    int add_more_people = room_capacity - number_of_people;
    int remove_people = number_of_people - room_capacity;
    if (number_of_people <= room_capacity)
        cout<<"It is legal to hold the meeting. It is legal to have "<<add_more_people<<" more attend the meeting";
    else
        cout<<"It is illegal to hold the meeting due to fire regulations. "<<remove_people<<" need to leave in order to meet fire regulations";
    return 0;
}
