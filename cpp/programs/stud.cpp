 /*
 Source code : class definition for student entity
 Program by : Anil Donwade
 Date : 9-1-2024
 */
 #include"stud.hpp"
 using namespace std;

 //constructors
 student::student(){
 name="A1";
 rollno=1;
 }

 student::student(string name, int rollno){
 this->name=name;
 this->rollno=rollno;
 }

 //accessors
 string student::get_name(){
 return name;
 }

 int student::get_rollno(){
 return rollno;
 }

 //mutators
 void student::set_name(string name){
 this->name = name;
 }

 void student::set_rollno(int rollno){
 this->rollno=rollno;
 }