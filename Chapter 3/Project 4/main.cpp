#include <iostream>
#include <string>
using namespace std;

int main()
{
    string card_value;
    char calculate, ace_card;
    int score, card_num;


    do {
        score = 0;
        ace_card = false;
        cout<<"How many cards do you have? 2, 3, 4, or 5: \n";
        cin>>card_num;
        while (card_num < 2 || card_num > 5) {
            cout << "Please enter a valid number of cards (2, 3, 4, or 5): \n";
            cin >> card_num;
        }
        while (card_num > 0) {
            cout<<"What is card number? (a, q, k, j, 1, 2, 3...10): \n";
            cin>>card_value;
            if (card_value == "a" || card_value == "A") {
                ace_card =true;
            }
            else if (card_value == "k" || card_value == "K" ||
                    card_value == "q" || card_value == "Q" ||
                    card_value == "j" || card_value == "J") {
                score += 10;
            }
            else if (card_value == "10") {
            score += 10; // Handle the special case for 10
            }
            else if (card_value >= "2" && card_value <= "9") {
            score += stoi(card_value); // For single-digit numbers
        }
            else {
                cout << "Invalid card input. Please enter a valid card (a, k, q, j, 1, 2, 3, ...10).\n";
                continue;
            }
            card_num--;
        }
        if (score >= 11 && ace_card == true) {
            score += 1;
        }
        else if (score <= 10 && ace_card == true) {
            score += 11;
        }
        if (score <= 21) {
            cout<<"Your final score in blackjack is "<<score;
        }
        else {
            cout<<"You busted with a score of "<<score;
        }
        cout<<"\nDo you want to calculate again? (y/n) \n";
        cin>>calculate;
    }while (calculate == 'y' || calculate == 'Y');
    return 0;
}
/*//Write a program that scores a blackjack hand. In blackjack, a player receives
//from two to five cards. The cards 2 through 10 are scored as 2 through
//10 points each. The face cards—jack, queen, and king—are scored as 10
//points. The goal is to come as close to a score of 21 as possible without
//going over 21. Hence, any score over 21 is called “busted.” The ace can
// as either 1 or 11, whichever is better for the user. For example, an
ace and a 10 can be scored as either 11 or 21. Since 21 is a better score, this
hand is scored as 21. An ace and two 8s can be scored as either 17 or 27.
Since 27 is a “busted” score, this hand is scored as 17.
 The user is asked how many cards she or he has, and the user responds with
one of the integers 2, 3, 4, or 5. The user is then asked for the card values. Card
values are 2 through 10, jack, queen, king, and ace. A good way to handle
input is to use the type char so that the card input 2, for example, is read as the
character '2', rather than as the number 2. Input the values 2 through 9 as the
characters '2' through '9'. Input the values 10, jack, queen, king, and ace as
the characters 't', 'j', 'q', 'k', and 'a'. (Of course, the user does not type in
the single quotes.) Be sure to allow upper- as well as lowercase letters as input.
 After reading in the values, the program should convert them from character values to numeric card scores, taking special care for aces. The output is
either a number between 2 and 21 (inclusive) or the word Busted. You are
likely to have one or more long multiway branches that use a switch statement or nested if-else statement. Your program should include a loop that
lets the user repeat this calculation until the user says she or he is done.*/