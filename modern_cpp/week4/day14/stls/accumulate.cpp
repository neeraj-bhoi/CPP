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
        rule1 : default operation is binary +
    */

    std::cout << std::accumulate(
        data1.begin(),
        data1.end(),
        0.0f,           //initial value (of answer_upto_current_point)
        [](float answer_upto_current_point, const Employee emp) {
            return answer_upto_current_point + emp.salary();
        }
    );

    std::cout << std::accumulate(
        data1.begin(),
        data1.end(),
        0.0f,           //initial value (of answer_upto_current_point)
        [](float answer_upto_current_point, const Employee* emp) {
            return answer_upto_current_point + emp->salary();
        }
    );

    std::cout << std::accumulate(
        data1.begin(),
        data1.end(),
        0.0f,           //initial value (of answer_upto_current_point)
        [](float answer_upto_current_point, const EmpSptr emp) {
            return answer_upto_current_point + emp->salary();
        }
    );

}


/*
    functional programming:
        - map : applying a logic on alll items in data collection(one by one)
        - filter : extract items that satisfy a condition from the data collection
        - reduce : collecting, summerizing, gathering, converting multiple items into a
            single item based on a binary operation....
            {
                {10, 20, 30, 40, 50}
                
                - reduce 5 numbers into 1 number by summation aggregation
                - reduce 5 numbers into 1 by product aggregation
            }
    
    reduce is the inspiration of accumulator
*/