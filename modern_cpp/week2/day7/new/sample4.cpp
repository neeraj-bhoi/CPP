#include<iostream>
#include<vector>
#include<functional>
#include<memory>


class Employee{
private:
    int _id;
    std::string _name;
    float _salary;

public:
    Employee() = default;
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
    Employee(Employee&&) = delete;
    Employee& operator=(Employee&&) = delete;
    ~Employee() = default;

    Employee(int id, std::string name, float salary):
        _id{id}, _name{name}, _salary{salary}
    {}

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    float operator+ (const Employee& rhs) {
        return _salary + rhs._salary;
    }

    float operator- (const Employee& rhs) {
        return _salary - rhs._salary;
    }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    void operator()() {
        std::cout<<"tax for this employee at 10%.. "<< _salary * 10 / 100;
    }

};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary;
    return os;
}

/*
    objective : take a container of raw pointers to employee and filter and print details based on predicate passed
*/


//raw pointer
void Adaptor(
    const std::vector<Employee*>& data,
    std::function<bool(Employee*)> predicate
) 
{
    for(Employee* ptr : data) {
        if(predicate(ptr)) {
            std::cout<< *ptr <<"\n";
        }
    }
}

//smart pointer
using EmployeePointer = std::shared_ptr<Employee>;
void Adaptor(
    const std::vector<EmployeePointer>& data,
    std::function<bool(EmployeePointer)> predicate
) 
{
    for(EmployeePointer ptr : data) {
        if(predicate(ptr)) {
            std::cout<< *ptr <<"\n";
        }
    }
}



int main() {
    std::vector<Employee*> data{
        new Employee(101, "harshit", 78000),
        new Employee(102, "neeraj", 50000)
    };

    

    // find employee whose salary is above 8000.0f
    Adaptor(
        data,
        [](Employee* emp) { 
            if(emp) {
                return emp->salary() > 8000.0f;
            } else {
                return false;
            }
         }
    );


    std::vector<EmployeePointer> data2 {
        std::make_shared<Employee>(101, "harshit", 78000),
        std::make_shared<Employee>(102, "neeraj", 50000)
    };

    Adaptor(
        data2,
        [](EmployeePointer emp) { 
            if(emp) {
                return emp->salary() > 8000.0f;
            } else {
                return false;
            }
         }
    );
}