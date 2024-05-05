/*
Program : To demonstrate the default arguments to function paramete
Program by : Anil Donwade
Date : 9-1-2024
*/

#include<iostream>
using namespace std;

 //a function having default argument
 inline int sum(int x=45, int y=1){
 return x + y;
 }

 //main function using default arguments to a sum() function
 int main(){
 int s = sum(100, 200); // two arguments
 cout << "Sum of " << 100 << " and " << 200 << " is: " << s << endl;

 s = sum(100); // one arguments
 cout << "Sum of " << 100 << " and " << 200 << " is: " << s << endl;

 s = sum(); //no arguments
 cout << "Sum of " << 100 << " and " << 200 << " is: " << s << endl;
 }
 