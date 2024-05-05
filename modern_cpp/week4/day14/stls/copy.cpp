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

    EmployeeContainer result1(data1.size()); //so that destination is of same size as source
    std::copy(
        data1.begin(),
        data1.end(),
        result1.begin()
    );
    // copy all elements from begining of data1 up to but not including the end of data1 to the result1 vector from the begining of result1.
    // to copy Employee, copy constructor should be enabled


    EmployeePointerContainer result2(data2.size());
    std::copy(
        data2.begin(),
        data2.end(),
        result2.begin()
    );



    EmployeeSmartContainer result3(data3.size());
    std::copy(
        data3.begin(),
        data3.end(),
        result3.begin()
    );

    for(auto d : result1) {
        std::cout<<d.salary()<<" ";
    }
    std::cout<<"\n";
    for(auto d : result2) {
        std::cout<<d->salary()<<" ";
    }
    std::cout<<"\n";
    for(auto d : result3) {
        std::cout<<d->salary()<<" ";
    }

}