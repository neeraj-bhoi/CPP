#include<bits/stdc++.h>
using namespace std;

class employee {
    static int total_count;
    string name;
    int salary;

    int* deptnoptr;         //if ptr variable is present in class, always deep copy constructors;

    public : 
        employee() {
            name = "";
            salary = 0;
            total_count++;
            deptnoptr = new int;
            deptnoptr = 0;
        }

        employee(string name, int salary, int deptno) {
            this -> name = name;
            this -> salary = salary;
            deptnoptr = new int;           //dyanamic memory allocation;
            *deptnoptr = deptno;        //
            total_count++;
        }

        // //shallow copy constructor
        // employee(employee &e) {
        //     name = e.name;
        //     salary = e.salary;
        //     deptnoptr = new int;
        //     deptnoptr = e.deptnoptr;    /// only address gets coppied;
        //     total_count++;
        // }

    //deep copy constructor
        employee(employee &e) {
            name = e.name;
            salary = e.salary;
            deptnoptr = new int;
            *deptnoptr = *e.deptnoptr;    /// values gets copied
            total_count++;
        }

        static int get_total_count() {
            return total_count;
        }

        void display() {
            cout<<"\n name = "<<this -> name;
            cout<<"\n salary = "<<this -> salary;
        }


        void add_salary(int n) {
            this -> salary += n;
        }

        ~employee() {
            cout<<"\n object destroyed";
            delete deptnoptr;
        }
};

int employee:: total_count = 0;

int main() {
    employee e1;
    employee e2("neeraj", 20000, 104);
    employee e3(e2);

    e1.display();
    e2.display();
    e3.display();

    e3.add_salary(2000);
    cout<<"\n\n after changing e3 salary : \n";
    e3.display();

    cout<<"\n\n\n";


    employee e4("jay", 17000, 104);
    employee e5(e4);
    e4.display();
    e5.display();

    cout<<endl<<endl<<" total employee count : "<<employee::get_total_count();
    cout<<"\n ---------main ended-------------";
}