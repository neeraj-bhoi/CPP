 /*
 Program : To demostrate the creation of class for the employee
 Program By : Anil Donwade
 Date : 8-Jan-2014

 THE employee CLASS CODE REQUIRES DEBUGGING
 */

 //include files
 #include<iostream>
 using namespace std;

 //class definition for the employee entity
 class employee{
 //by default private, hence these data members are accessed
 unsigned int empid; //data member
 string name; //data member
 float salary; //data member
 int *deptnoptr; //pointer member

 //static members
 static int total_emp; //static variable data member
 static const int WORKING_HOURS=8; //static constant data member24: static int empidsr; //static variable data member
 enum department {DESIGN=1, PRODUCTION, SYSTEM, ACCOUNT, MARKE26: dept; //data member of a class


 public:
 //zero parameter constructor
 employee(){
 cout << "This is ZERO parameter constructor..." << endl;
 cout << "salary would be garbage value, since not
 cout << "... but name would be initialized will NULL" << endl35:
 deptnoptr = new int; //dynamic memory allocation
 deptnoptr = 0; //initial value, by default is zero
 total_emp++; //increment the count of emplyees
 empidsr++; //also increment serial for emplyees
 empid=empidsr; //set serial as the id for emplayee
 }

 //two parameter constructor
 employee(const string name, const float salary){
 cout << "This is two parameter constructor..." << endl;
 this->name = name;
 this->salary = salary;
 deptnoptr = new int; //dynamic memory allocation
 total_emp++;
 empidsr++;
 empid=empidsr;
 }

 //three parameter constructor
 employee(string name, float salary, int deptno){
 cout << "This is two parameter constructor..." << endl;
 this->name = name;
 this->salary = salary;
 deptnoptr = new int; //dynamic memory allocation
 *deptnoptr = deptno;
 total_emp++;
 empidsr++;
 empid=empidsr;
 }

 //copy constructor - shallow copy
 /* employee(employee &e){
 name = e.name;
 salary = e.salary;

 deptnoptr = e.deptnoptr; //only address gets copied

 total_emp++;
 }
 */

 employee(employee &e){ //deep-copy constructor
 name = e.name;
 salary = e.salary;
 deptnoptr = new int; //new location is allocated

 //data pointed by pointer in the passed object gets copied
 //in the pointer of this pointer
 *deptnoptr = *(e.deptnoptr);

 total_emp++;
 empidsr++;
 empid=empidsr;
 }

 //getter
 float get_salary(){
 return this->salary;
 }

 //setter
 void set_salary(float new_salary){
 this->salary = new_salary;
 }

 //static-getter
 static int get_total_emp(){
 return total_emp;
 }

 //static-getter for constant
 static int get_working_hours(){
 return WORKING_HOURS;
 }

 void display(){
 cout << "Employee ID:" << empid << " Name : "<<this->name<< "113: }

 //destructor
 //shallow copy will lead to deptnoptr as a dangling pointer
 //deep copy will ensure avoiding the dangling pointer
 ~employee() {
 cout << "Destroying the object of Employee...\n";
 delete deptnoptr; //deallocate dynamically allocated mem121: }

 //operator overloading functions
 friend istream& operator>>(istream& isr, employee& empr);
 friend ostream& operator<<(ostream& osr, employee empr);
 };

 //global space, used to initialize static members of the class
 int employee::total_emp=0; //static class member initialization
 int employee::empidsr=1000;


 //operator overloading function to accept employee data
 istream& operator>>(istream& isr, employee& empr){
 int d;
 cout << "Enter Name: "; cin >> empr.name;
 cout << "Enter Salary: "; cin>> empr.salary;
 cout << "Enter Department Number(1-5): "; cin >> d; /* *(empr.dep
 // enum department {DESIGN=1, PRODUCTION, SYSTEM, ACCOUNT, MAR
 //if(*(empr.deptnoptr)==1)
 if
 empr.dept = empr.department::DESIGN;
 else if(*(empr.deptnoptr)==2)
 empr.dept = empr.department::PRODUCTION;
 else if(*(empr.deptnoptr)==3)
 empr.dept = empr.department::SYSTEM;
 else if(*(empr.deptnoptr)==4)
 empr.dept = empr.department::ACCOUNT;
 else
 empr.dept = empr.department::MARKETING;
 return isr;
 }

 //operator overloading function to display employee object
 ostream& operator <<(ostream& osr, employee empr){
 string departments[]={"DESIGN", "PRODUCTION", "SYSTEM", "ACCOUNT"157: cout << "Name: " << empr.name << endl;
 cout << "Salary: " << empr.salary << endl;
 cout << "Department: " << departments[empr.dept] << endl;
 return osr;
 }

 //
 ////main() function definition
 //int main(){
 // cout << "---------- main() started -------------" << endl
 // /* object creation:
 // e1, e2, e3, e4, e5, e6 are created as objects of employee c
 // employee e1; //default constructor will used to initia
 // cout << "e1 salary :"<< e1.get_salary()<< endl;
 //
 // employee e2("Vijay", 20000); //two parameter constructor
 // cout << "e2 salary :"<< e2.get_salary() << endl;
 //
 // e1.display();
 // e2.display();
 // cout << "Total employees are: " << employee::get_total_em
 //
 // employee e3(e2); //copy constructor
 // cout << "COPY CONSTRUCTOR:"<< endl;
 // e3.display();
 // e3.set_salary(22000);
 // e3.display();
 // e2.display();
 //
 // //create an array of employees
 // //employee arr[2]={employee("John",18000), employee("Ajay
 // employee emp_arr[2]={e2, e3};
 //
 // cout << "Array of employees output: "<< endl;
 // for (int i = 0; i < 2; i++)
 // emp_arr[i].display();
 //
 // cout << "Total employees are: " << employee::get_total_em
 // cout << "---------- main() ended -------------" << endl;
 //
 // //shallow copy demo
 // employee e4("Jay", 17000, 104);
 // e4.display();
 //
 // /* copy constructor, in the absence of the deep copy cons
 // employee e5(e4);
 // e5.display();
 //
 // /* object assignment: deep copy-constructor is used for t
 // cout << "Assigning object: "<< endl;
 // employee e6=e5;
 // e5.display();
 //
 // cout << "Working hours for all emplyees: "
 // return 0;
 //}
 //
 