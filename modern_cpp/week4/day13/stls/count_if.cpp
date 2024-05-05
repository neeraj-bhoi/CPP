/*
    how to use stl algorithms more efectively
*/

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

//count instances matching a condition
/*
    count instances matching with given condition
    condition is written as predicate.
    return value is the final count.
*/
// count_if ------> returns count
    int count = std::count_if(
        data1.begin(),
        data1.end(),
        [](Employee& emp) { return emp.salary() > 40000.0f; } 
    );
    std::cout << std::count_if(
        data2.begin(),
        data2.end(),
        [](Employee*& emp) { return emp->salary() > 40000.0f; } 
    );
    std::cout << std::count_if(
        data3.begin(),
        data3.end(),
        [](EmpSptr& emp) { return emp->salary() > 40000.0f; } 
    );

}