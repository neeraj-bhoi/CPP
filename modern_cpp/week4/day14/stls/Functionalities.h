#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Employee.h"
#include<memory>
#include<vector>

using EmployeeContainer = std::vector<Employee>;
using EmployeePointerContainer = std::vector<Employee*>;
using EmpSptr = std::shared_ptr<Employee>;
using EmployeeSmartContainer = std::vector<EmpSptr>;

void CreateEmployees(EmployeeContainer& data) {
    data.push_back(
        Employee("harshit", 56000.0f, "Trainer", 10)
    );

    data.push_back(
        Employee("harshit", 66000.0f, "Trainer", 10)
    );

    data.push_back(
        Employee("harshit", 76000.0f, "Trainer", 10)
    );
}

void CreateEmployeesPointers(EmployeePointerContainer& data) {
    data.push_back(
        new Employee("harshit", 56000.0f, "Trainer", 10)
    );

    data.push_back(
        new Employee("harshit", 66000.0f, "Trainer", 10)
    );

    data.push_back(
        new Employee("harshit", 76000.0f, "Trainer", 10)
    );
}

void CreateEmployeesSmartPointers(EmployeeSmartContainer& data) {
    data.push_back(
        std::make_shared<Employee>("harshit", 56000.0f, "Trainer", 10)
    );

    data.push_back(
        std::make_shared<Employee>("harshit", 66000.0f, "Trainer", 10)
    );

    data.push_back(
        std::make_shared<Employee>("harshit", 76000.0f, "Trainer", 10)
    );
}

#endif // FUNCTIONALITIES_H
