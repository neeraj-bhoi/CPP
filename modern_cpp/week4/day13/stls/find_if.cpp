/*
    how to use stl algorithms more efectively
*/

#include"Functionalities.h"
#include<algorithm>
#include<numeric>
#include<functional>


// void Search(EmployeeContainer& data, const std::function<bool(const Employee&)>& fn) {
//     auto itr = std::find_if(
//         data.begin(),
//         data.end(),
//         fn
//     );
//     if(itr == data.end()) {
//         std::cerr<<"object not found\n";
//     } else {
//         std::cout<<"object found : "<< *itr <<"\n";
//     }
// }

template <typename T, typename P>
/*T::const_iterator*/auto Search(const T& data, const P& fn) {
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        fn
    );
    if(itr == data.end()) {
        std::cerr<<"object not found\n";
        return itr;
    } else {
        std::cout<<"object found : "<<"\n";
        return itr;
    }
}


int main() {
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartContainer data3;

    CreateEmployees(data1);
    CreateEmployeesPointers(data2);
    CreateEmployeesSmartPointers(data3);
    ///////////////////////////////////////////////////////////
/*
    2)std::find_if
        std::find_if returns "iterator the first matching object" if found.
        if match is not found -> it returns end iterator
*/
    auto itr1 = Search<EmployeeContainer, std::function<bool(const Employee&)>> (
            data1,
            [](const Employee& emp) { return (emp.salary() > 40000.0f); }
        );

    auto itr2 = Search<EmployeePointerContainer, std::function<bool(const Employee*)>> (data2, [](const Employee* emp) { return (emp->salary() > 40000.0f); });
    auto itr3 = Search<EmployeeSmartContainer, std::function<bool(const EmpSptr)>> (data3, [](const EmpSptr emp) { return (emp->salary() > 40000.0f); });


    // std::find_if(
    //     data3.begin(),
    //     data3.end(),
    //     [](const EmpSptr& emp) { return emp -> salary() > 40000.0f; }
    // );
}