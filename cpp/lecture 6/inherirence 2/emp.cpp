/*
    source file : employee class defination
*/

#include"emp.hpp"

employee :: employee() {
    // cout<<"employee constructor called...\n";
    name = "ZZZ";
    salary = 0.0f;
}

employee :: employee(char* name, float salary) {
    // cout<<"employee constructor called...\n";
    this -> name = name;
    this -> salary = salary;
}

employee :: employee(const employee& e) {
    this -> name = e.name;
    this -> salary = e.salary;
}


void employee :: set_name(char* name) {
    this -> name = name;
}

char* employee :: get_name() {
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
    // delete name;
}


//MANAGER CLASS
manager :: manager() : employee() {
    // cout<<"manager constructor called...\n";
    hra = 0.0f;
}

manager :: manager (char* name, float salary, float hra) : employee(name, salary){
    // cout<<"manager constructor called...\n";
    this -> hra = hra;
}

manager :: manager (const manager& m) : employee(m){
    this -> hra = m.hra;
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

general_manager::general_manager(char* name, float salary, float hra, char* region) : manager(name, salary, hra) {
    this -> region = region;
}

general_manager :: general_manager(const general_manager& g) : manager(g) {
    this -> region = g.region;
}


void general_manager :: display() {
    float sal = this -> get_salary();
    manager::calculate_slary();

    // cout<<this -> get_name()<<"  "<<sal<<"  "<<this ->get_hra()<<"  "<<salary<<"  "<<region<<endl;
    manager::display();
    cout<<region<<endl;
}