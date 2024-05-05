/*

    check if all instancesmeet a condition

*/


#include"Functionalities.h"
#include<algorithm>
#include<numeric>
#include<functional>



int main() {
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartContainer data3;

    CreateEmployees(data1);
    CreateEmployeesPointers(data2);
    CreateEmployeesSmartPointers(data3);
    ///////////////////////////////////////////////////////////

    std::cout << std::all_of(           //returns a bool
        data1.begin(),
        data1.end(),
        [](const Employee& emp) { return emp.salary() > 40000.0f; }
    );

}