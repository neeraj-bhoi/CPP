#include <iostream>

class IntegerPointerClass {
private:
    int* data; // Integer pointer as data member

public:
    // Default Constructor
    IntegerPointerClass() : data(nullptr) {
        std::cout << "Default Constructor" << std::endl;
    }

    // Parameterized Constructor
    IntegerPointerClass(int value) : data(new int(value)) {
        std::cout << "Parameterized Constructor" << std::endl;
    }

    // Copy Constructor
    IntegerPointerClass(const IntegerPointerClass& other) : data(nullptr) {
        if (other.data != nullptr) {
            data = new int(*(other.data));
        }
        std::cout << "Copy Constructor" << std::endl;
    }

    // Move Constructor
    IntegerPointerClass(IntegerPointerClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move Constructor" << std::endl;
    }

    // Copy Assignment Operator
    IntegerPointerClass& operator=(const IntegerPointerClass& other) {
        if (this != &other) {
            delete data;
            if (other.data != nullptr) {
                data = new int(*(other.data));
            } else {
                data = nullptr;
            }
        }
        std::cout << "Copy Assignment Operator" << std::endl;
        return *this;
    }

    // Move Assignment Operator
    IntegerPointerClass& operator=(IntegerPointerClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        std::cout << "Move Assignment Operator" << std::endl;
        return *this;
    }

    // Destructor
    ~IntegerPointerClass() {
        delete data;
        std::cout << "Destructor" << std::endl;
    }

    // Overload + operator
    IntegerPointerClass operator+(const IntegerPointerClass& other) const {
        int sum = (data ? *data : 0) + (other.data ? *(other.data) : 0);
        return IntegerPointerClass(sum);
    }

    // Overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const IntegerPointerClass& obj) {
        os << (obj.data ? *(obj.data) : 0);
        return os;
    }
};

int main() {
    // Test various constructors, operators, and destructor
    IntegerPointerClass obj1;          // Default constructor
    IntegerPointerClass obj2(42);       // Parameterized constructor
    IntegerPointerClass obj3 = obj2;    // Copy constructor
    IntegerPointerClass obj4 = std::move(obj3);  // Move constructor
    IntegerPointerClass obj5;
    obj5 = obj2;                       // Copy assignment operator
    IntegerPointerClass obj6;
    obj6 = std::move(obj5);            // Move assignment operator
    IntegerPointerClass obj7 = obj2 + obj6;      // Overload + operator

    std::cout << "obj2: " << obj2 << std::endl;

    return 0;
}
