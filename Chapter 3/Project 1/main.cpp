#include <iostream>
#include <string>
using namespace std;

int main()
{
  string weekday;
  int call_hour, call_minute, call_time ;
  double call_cost;
  char continue_calc;
 do {
  cout<<"Enter which day of the week you made your call?\n"
        "Enter using the format Mo, Tu, We, Th, Fr, Sa, Su\n";
  cin>>weekday;
  for (char &c : weekday) {
   c = tolower(c);
  }
  cout<<"What time did you make your call? Use 24-hour notation (HH:MM): \n";
  scanf("%d:%d", &call_hour, &call_minute);
  cout<<"How long was your call? Round to the nearest whole minute:\n";
  cin>>call_time;
  if (weekday == "sa" || weekday == "su") { //make it so lowercase is ok too
   call_cost = .15 * call_time ;
  }
  else {
   if (call_hour >= 8 && call_hour <= 18) {
    call_cost = call_time * .40;
   }
   else {
    call_cost = call_time * .25;
   }
  }
  cout<<"Your call cost $"<<call_cost;
  cout<<"\nWould you like to make another calculation ( y / n)? \n";
  cin>>continue_calc;
 } while (continue_calc == 'y'  || continue_calc == 'Y');
  return 0;
}

