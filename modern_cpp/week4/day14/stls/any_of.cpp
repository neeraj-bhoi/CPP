#include"Functionalities.h"
#include<algorithm>
#include<numeric>




int main() {
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartContainer data3;

    CreateEmployees(data1);
    CreateEmployeesPointers(data2);
    CreateEmployeesSmartPointers(data3);
    ///////////////////////////////////////////////////////////

    /*
        check if "any of" (at least one) instances satisfy condition
    */

    std::cout << std::boolalpha << std::any_of(
        data1.begin(),
        data1.end(),
        [](const Employee& emp) { return emp.salary() > 40000.0f; }
    );

    std::cout << std::boolalpha << std::any_of(
        data2.begin(),
        data2.end(),
        [](const Employee* emp) { return emp->salary() > 40000.0f; }
    );

    std::cout << std::boolalpha << std::any_of( 
        data3.begin(),
        data3.end(),
        [](const EmpSptr emp) { return emp->salary() > 40000.0f; }
    );

}