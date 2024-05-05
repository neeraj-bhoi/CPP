/*
    source file : employee class defination
*/

#include"emp.hpp"

employee :: employee() {
    // cout<<"employee constructor called...\n";
    name = "ZZZ";
    salary = 0.0f;
}

employee :: employee(string name, float salary) {
    // cout<<"employee constructor called...\n";
    this -> name = name;
    this -> salary = salary;
}

void employee :: set_name(string name) {
    this -> name = name;
}

string employee :: get_name() {
    return name;
}

void employee :: set_salary(float salary) {
    this -> salary = salary;
}

float employee :: get_salary() {
    return salary;
}

employee :: ~employee() {
    // cout<<"employee destructor called...\n";
}


//MANAGER CLASS
manager :: manager() : employee() {
    // cout<<"manager constructor called...\n";
    hra = 0.0f;
}

manager :: manager (string name, float salary, float hra) : employee(name, salary){
    // cout<<"manager constructor called...\n";
    this -> hra = hra;
}

void manager :: set_hra(float hra) {
    this -> hra = hra;
}

float manager :: get_hra() {
    return hra;
}

void manager :: calculate_slary() {
    salary += hra;
}

void manager::display() {
    cout<<this -> get_name()<<"  "<<this -> get_salary()<<"  "<<this -> get_hra()<<endl;
}

manager ::~manager() {
    // cout<<"manager destructor called...\n";
}

general_manager :: general_manager() : manager(){
    this -> region = "Z";
}

general_manager::general_manager(string name, float salary, float hra, string region) : manager(name, salary, hra) {
    this -> region = region;
}


void general_manager :: display() {
    float sal = this -> get_salary();
    manager::calculate_slary();

    // cout<<this -> get_name()<<"  "<<sal<<"  "<<this ->get_hra()<<"  "<<salary<<"  "<<region<<endl;
    manager::display();
    cout<<region<<endl;
}