 /*
 Program : To make use of enumerated data type
 */
 #include<iostream>
 using namespace std;

 //enum definition
 enum Weekdays {
 SUNDAY = 5,
 MONDAY,
 TUESDAY,
 WEDNESDAY,
 THURSDAY,
 FRIDAY
 };

 int main(){
 //1
 enum Weekdays wd; //enum variables
 wd = Weekdays::SUNDAY;
 wd = Weekdays::WEDNESDAY;
 switch(wd){
 case SUNDAY: cout << "Today is Sunday " << endl;
 break;
 case MONDAY: cout << "Today is Monday " << endl;
 break;
 case TUESDAY: cout << "Today is Tuesday " << endl;
 break;
 case WEDNESDAY: cout << "Today is Sunday " << endl;
 break;
 case THURSDAY: cout << "Today is Monday " << endl;
 break;
 case FRIDAY: cout << "Today is Tuesday " << endl;
 default: cout << "Invalid day" << endl;
 }

 //2
 enum Weekdays x = wd;

 if(x == Weekdays::SUNDAY)
 cout << "Sunday" << endl;
 else
 cout << "No Holiday......";
 /* int x = wd + 1;
 if(x == 1 ) cout << "Monday" << endl;*/

 //3
 int day;
 cout << "Enter a number between 0-7:"<< endl;
 cin >> day;

 //decide the weekday based on the number
 enum Weekdays wd1;
 wd1 = day == 1 ? Weekdays::SUNDAY :
 (day == 2 ? Weekdays::MONDAY :
 (day == 3 ? Weekdays::TUESDAY :
 (day == 4 ? Weekdays:: WEDNESDAY:
 (day == 5 ? Weekdays:: THURSDAY:
 (day == 6 ? Weekdays::FRIDAY :
 Weekdays::SUNDAY )))));

 //array of strings
 string cities[]={"Delhi", "Mumbai", "Banglore", "Chennai", "Kolkat64"};
 cout << cities[wd1];
 }