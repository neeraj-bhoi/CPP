/*
Program : To overload + operator to cancatinate two strings
Program By : Anil Donwade
Program : 10-1-2024
*/

#include<iostream>
#include<cstring>
using namespace std;
class MyString{
 char * cptr;
 public:
 MyString(){
 cptr = new char;
 *cptr='\0';
 }

 MyString( const char * cptr){
 int len;
 len=strlen(cptr);
 this->cptr = new char[len+1];
 strcpy( this->cptr, cptr);
 }

 void display(){
 cout << cptr << endl;
 }

 //operator overloading function
 MyString operator+(MyString s){
 static int count = 0;
 count++;
 cout << " operator overloading function called ......"<< count33: MyString temp/*=NULL*/;
 int len1 = strlen(this->cptr); //first string length
 int len2 = strlen(s.cptr); //second string length

 //allocate memory for resulting string from the caoncatination38: temp.cptr = new char[len1+len2+1];
 if(strlen(temp.cptr) == 0){
 cout << "Memory allocation error...." << endl;
 exit(0);
 }
 int l=strlen(temp.cptr );
 cout << "Allocated memory size is :" << l << endl;
 //transfer characters from both strings to allocated memory
 strcpy(temp.cptr, this->cptr); //copy the first string
 strcat(temp.cptr, s.cptr);
 l=strlen(temp.cptr );
 cout << "Allocated memory size is :" << l << endl;
 cout <<"inside operator overloading function, cptr=" << temp.c51:
 return temp; //return the resulting string
 }
 ~MyString(){
 delete cptr;
 }
 };


 int main(){
 MyString s1("C++"), s2("Programming"), space(" ");

 // strcpy(s1, );
 // strcpy(s2, );

 s1.display();
 s2.display();

 MyString s3;

 s3 = s1 + space + s2; // => s3=s1.operator+(s2)

 s3.display(); // ?
 /* s1.~MyString();
 s2.~MyString();
 s3.~MyString();*/

 //second scenario
 MyString s4("Good"), s5("Morning"), dash("-"), s6;
 s6 = s4 + dash + s5;
 s6.display();

 }