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

    //result

/*
    1) copy operation : so copy has to be supported
    2) we dont know how many instances will satisfy the condition
    3) to copy from source to destination , destination has to already be initialized with memory allocated to it
*/


    EmployeeContainer result1(data1.size());
    //initialize of size data1.size() -> later will change the result.size

    //condition copy
    auto itr = std::copy_if(
        data1.begin(),
        data1.end(),
        result1.begin(),
        [](const Employee& emp) { return emp.salary() > 40000.0f; }
    );
    //compiler creates iterator in result vector till where copy happened

    //fix the size difference
    std::size_t actual_size = std::distance(result1.begin(), itr);
    //distance finds the absolute difference between 2 iterators

    result1.resize(actual_size);


    std::cout<<"\n\n";


    EmployeePointerContainer result2(data2.size());

    auto itr2 = std::copy_if(
        data2.begin(),
        data2.end(),
        result2.begin(),
        [](const Employee* emp) { return emp->salary() > 40000.0f; }
    );
    std::size_t actual_size = std::distance(result2.begin(), itr2);
    result1.resize(actual_size);

}