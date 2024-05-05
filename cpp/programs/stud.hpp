/*
Source code : Header file for student class
*/
#ifndef STUD_HPP
#define STUD_HPP
#include<string>
using namespace std;

class student{
 string name;
 int rollno;
 public:
 //constructors
 student();
 student(string name, int rollno);

 //getters
 string get_name();
 int get_rollno();

 //setters
 void set_name(string name);
 void set_rollno(int rollno);
 };
 #endif