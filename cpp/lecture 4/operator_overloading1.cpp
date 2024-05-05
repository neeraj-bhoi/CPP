#include <iostream>

// Sample class for demonstration purposes
class ComplexClass {
private:
    int value;

public:
    // Constructor
    ComplexClass(int val = 0) : value(val) {}

    // Overloading the address-of operator
    ComplexClass* operator&() {
        // Return the address of the current instance
        return this;
    }

    // Overloading the pointer-to-member operators
    int ComplexClass::*operator->*(int val) {
        // Return a member pointer
        return &ComplexClass::value;
    }

    // Overloading the comma operator
    ComplexClass operator,(const ComplexClass& other) {
        // Combine two instances and return a new instance
        return ComplexClass(value + other.value);
    }

    // Overloading the conditional operator
    ComplexClass operator ?:(bool condition, const ComplexClass& trueValue, const ComplexClass& falseValue) {
        return condition ? trueValue : falseValue;
    }

    // Overloading the scope resolution operator
    static void StaticFunction() {
        std::cout << "Static function called." << std::endl;
    }

    // Overloading the logical AND operator
    bool operator&&(const ComplexClass& other) const {
        return value && other.value;
    }
};

int main() {
    ComplexClass obj1(10);
    ComplexClass obj2(20);

    // Using the overloaded operators
    ComplexClass* ptr = &obj1;
    int ComplexClass::*memberPtr = obj1->*5;
    ComplexClass result = obj1, obj2;  // Using the comma operator

    bool condition = true;
    ComplexClass result2 = condition ? obj1 : obj2;  // Using the conditional operator

    bool logicalAndResult = obj1 && obj2;  // Using the logical AND operator

    return 0;
}
