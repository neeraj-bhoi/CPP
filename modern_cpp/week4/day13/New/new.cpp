/*
    tax payers : Employees, BusinessOwners
    generally{
        make taxpayer base class, and 2 child classes Employee and BusinessOwners and 
        implement all functionalities.
    }

    to solve a problem where you can see a fixed structure
        - like only two child classes are required
        - don't want inheritence
    ** VARIENT comes into piture..
*/

#include<iostream>
#include<array>
#include<variant>   //for varient

/*
    ADT (algebric data type)
    varient is one such ADT
*/

class BusinessOwner
{
private:
    std::string _name;
    std::string _companyGstNumber;
    float _revenue;
    float _expences;

public:
    BusinessOwner() = default;
    ~BusinessOwner() = default;

    BusinessOwner(std::string name, std::string gstNumber, float revenue, float expences)
        : _name{name}, _companyGstNumber{gstNumber}, _revenue{revenue}, _expences{expences}
    {}

    std::string name() const { return _name; }

    float calculateTaxAmount() {return .3f * (_revenue - _expences);}

    float revenue() const { return _revenue; }
};



class Employee
{
private:
    std::string _name;
    float _salary;

public:
    Employee() = default;
    ~Employee() = default;

    Employee(std::string name, float sal)
        :_name{name}, _salary{sal}
    {}

    std::string name() const { return _name; }
};


using VType = std::variant<Employee*, BusinessOwner*>;  
using container = std::array<VType, 2>;

void CommonAction(container& arr) {                     //common function in both
    for(VType v : arr) {
        std::visit(
            [](auto&& val) { std::cout << val -> name() << "\n"; }, //auto&& -> template parameter for lambda
            v
        );
    }
}
/*
    for every element v in arr : visit v -> open it -> pass val as pointer -> access the function...
*/


void UnCommonFunction(container& arr) {                 //type specific function
    for(VType v : arr) {
        if(std::holds_alternative<BusinessOwner*> (v)) {
            BusinessOwner* ow = std::get<1> (v);
            std::cout<< ow -> revenue();
        }
    }
}
/*
    for each VType (varient) called "v",
        a) open variant and check if v holds an alternative of type BusinessOwner*
        b) if yes, get data from slot 1 of the variant (because slot 1 if for BusinessOwner*)
            now, save this to a variable and access revenue
*/


int main() {
    // Employee* emp = new Employee("rakshit", 67000.0f);
    // BusinessOwner* business = new BusinessOwner("xyz", "1910ahh", 100, 50);

    // container arr {emp, business};

    std::variant<int, std::string> v1;
        std::visit(
            [](auto&& val) { std::cout << val  << "\n"; }, //auto&& -> template parameter for lambda
            v1
        );

    /*
        varient of either Employee or BusinessOwner type
        only one of the above type at a time
        { FUNCTIONAL POLYMORPHISM }
    */

    
}

/*
    Employee | BusinessOwner                                Employee | BusinessOwner
    [ 0x111 , \\\\\\ ]                                         [ \\\\\\\ , 0x222 ] 
    <------------------------------------arr--------------------------------------->


    scenario1: I want to execute a function that is present in all types of the varient
        eg: getter for name
    
    scenario2: I want to call a function that only exisss in some but not all types in the variant
*/