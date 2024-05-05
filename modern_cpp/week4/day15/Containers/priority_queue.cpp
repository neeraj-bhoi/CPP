#include<queue>
#include<iostream>
#include<vector>
#include<functional>
#include"Employee.h"
#include"Functionalities.h"

struct Less_Comparator {
    bool operator() (int a, int b) {
        return a > b;
    }
};

template < typename T, typename C>
void Display(std::priority_queue<T, std::vector<T>, C> & pq) {
    while(!pq.empty()) {
        std::cout<<"popping : "<<pq.top()<<"\n";
        pq.pop();
    }
    std::cout<<"\n";
}

int main() {

    std::vector<int> data {11, 12, 13, 14, 15, 16};

    // example1 : int in priority queue, conparison from struct Less_Comparator type
    std::priority_queue<int, std::vector<int>, Less_Comparator> pq1;

    pq1.push(20);
    Display<int, Less_Comparator>(pq1);
    // Display<int, Less_Comparator>(pq1);

    // example2 : int in priority queue, conparator is a built in FUNCTOR object[std::greator<int>]
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2 (data.begin(), data.end());

    Display<int, std::greater<int>>(pq2);

    EmployeeContainer employees;
    CreateEmployees(employees);

    auto comp = [](const Employee& e1, const Employee& e2) {
        return e1.expYears() < e2.expYears();
    };
                                            //dsecltype -> because type of comp will be unknown
    std::priority_queue<Employee, std::vector<Employee>, decltype(comp)> pq3 (
        employees.begin(),
        employees.end(),
        comp
    );


    Display<Employee, decltype(comp)>(pq3);
    /*
        if using lambda as comparator, also pass lambda object as a parameter to constructor of priority queue
    */

    /*
        pq3 is a priority queue designed for storing employess (type Employee) It will be created by using std::vetor of employee type.
        The comparison logic comes from lamda object comp. Its data type is unknown to mem hencce I am asking compiler to provide declred
        type of comp 1.e dreclatype (comp)a as my third remplate parameter
    */
   
       //note : if using lamda as comparator, also lamda object as a parameter
       //to constructor of priority queue
}



