#include"Functionalities.h"
#include<algorithm>
#include<numeric>   //accumulator




int main() {
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartContainer data3;

    CreateEmployees(data1);
    CreateEmployeesPointers(data2);
    CreateEmployeesSmartPointers(data3);
    ///////////////////////////////////////////////////////////

    /*
        disignation of employee whose salary is min
        note: if there are 2 or more min values, first min is used
    */
    auto itr = std::min_element(
        data1.begin(),
        data1.end(),
        [](const Employee& emp1, const Employee& emp2) { return emp1.salary() < emp2.salary(); }
    );                                          //comparison logic or comparator

    std::cout<< " designatio of min salary : " <<(*itr).salary() <<"\n";







    auto itr2 = std::min_element(
        data2.begin(),
        data2.end(),
        [](const Employee* emp1, const Employee* emp2) { return emp1->salary() < emp2->salary(); }
    );                                          //comparison logic or comparator

    std::cout<< " designatio of min salary : " <<(*itr2)->salary() <<"\n";







    auto itr3 = std::min_element(
        data3.begin(),
        data3.end(),
        [](const EmpSptr emp1, const EmpSptr emp2) { return emp1->salary() < emp2->salary(); }
    );                                          //comparison logic or comparator

    std::cout<< " designatio of min salary : " <<(*itr3)->salary() <<"\n";


}