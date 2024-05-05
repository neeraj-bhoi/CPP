#include<iostream>
#include<memory>
#include<vector>
#include<numeric>


class Employee
{
private:
    std::string _name{""};
    float _salary{0.0f};
    std::string _designation{""};
    int _exp_years{-1};
public:
    Employee(std::string name, float salary, std::string designation, int exp_years)
        : _name{name}, _salary{salary}, _designation{designation}, _exp_years{exp_years}
     {}
    Employee() = default;
    Employee(const Employee&) = default;
    Employee(Employee&&) = default;
    Employee& operator=(const Employee&) = default;
    Employee& operator=(Employee&&) = default;
    ~Employee() = default;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    std::string designation() const { return _designation; }
    void setDesignation(const std::string &designation) { _designation = designation; }

    int expYears() const { return _exp_years; }
    void setExpYears(int exp_years) { _exp_years = exp_years; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);    
    Employee operator + (Employee & e) {
        Employee temp;
        temp._salary = this->_salary + e._salary;
        return temp;
    }

    Employee* operator + (Employee* e) {
        Employee* temp = new Employee();
        temp->_salary = this->_salary + e->_salary;
        return temp;
    }
};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _designation: " << rhs._designation
       << " _exp_years: " << rhs._exp_years;
    return os;
}


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
        new Employee("harshit", 56000.0f, "Trainer", 10)
    );

    data.push_back(
        new Employee("harshit", 56000.0f, "Trainer", 10)
    );
}

void CreateEmployeesSmartPointers(EmployeeSmartContainer& data) {
    data.push_back(
        std::make_shared<Employee>("harshit", 56000.0f, "Trainer", 10)
    );

    data.push_back(
        std::make_shared<Employee>("harshit", 56000.0f, "Trainer", 10)
    );

    data.push_back(
        std::make_shared<Employee>("harshit", 56000.0f, "Trainer", 10)
    );
}






int main() {
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartContainer data3;

    CreateEmployees(data1);
    CreateEmployeesPointers(data2);
    CreateEmployeesSmartPointers(data3);



    std::cout << std::accumulate(
        data1.begin(),
        data1.end(),
        Employee(),     
        [](Employee& e1, Employee e2) {
            return e1 + e2;
        }
    );

    std::cout << std::accumulate(
        data2.begin(),
        data2.end(),
        new Employee(),
        [](Employee* e1, Employee* e2) {
            return e1 + e2;
        }
    );

}