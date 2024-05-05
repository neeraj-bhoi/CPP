 /*
 Program : To make use of student class to create and manipulate the
 Program by : Anil Donwade
 Date : 9-1-2024
 */

 //include files
 #include"stud.cpp"
 #include<iostream>
 using namespace std;

 //main() function
 int main(){
 student s1;
 student s2("Vikas", 21);

 cout << s1.get_name() << ", " << s1.get_rollno()<< endl;
 cout << s2.get_name() << ", " << s2.get_rollno()<< endl;
 return 0;
 }