#include <iostream>

class ChallengingClass {
private:
    int value;

public:
    // Constructor
    ChallengingClass(int val) : value(val) {}

    // Overloading bitwise AND operator (&)
    ChallengingClass operator&(const ChallengingClass& other) const {
        return ChallengingClass(value & other.value);
    }

    // Overloading bitwise OR operator (|)
    ChallengingClass operator|(const ChallengingClass& other) const {
        return ChallengingClass(value | other.value);
    }

    // Overloading bitwise XOR operator (^)
    ChallengingClass operator^(const ChallengingClass& other) const {
        return ChallengingClass(value ^ other.value);
    }

    // Overloading bitwise NOT operator (~)
    ChallengingClass operator~() const {
        return ChallengingClass(~value);
    }

    // Overloading left shift operator (<<)
    ChallengingClass operator<<(int shift) const {
        return ChallengingClass(value << shift);
    }

    // Overloading right shift operator (>>)
    ChallengingClass operator>>(int shift) const {
        return ChallengingClass(value >> shift);
    }

    // Overloading equality operator (==)
    bool operator==(const ChallengingClass& other) const {
        return value == other.value;
    }

    // Overloading inequality operator (!=)
    bool operator!=(const ChallengingClass& other) const {
        return !(*this == other);
    }

    // Overloading bitwise AND assignment operator (&=)
    ChallengingClass& operator&=(const ChallengingClass& other) {
        value &= other.value;
        return *this;
    }

    // Overloading bitwise OR assignment operator (|=)
    ChallengingClass& operator|=(const ChallengingClass& other) {
        value |= other.value;
        return *this;
    }

    // Overloading bitwise XOR assignment operator (^=)
    ChallengingClass& operator^=(const ChallengingClass& other) {
        value ^= other.value;
        return *this;
    }

    // Overloading stream insertion operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const ChallengingClass& obj) {
        os << obj.value;
        return os;
    }
};

int main() {
    ChallengingClass obj1(5);
    ChallengingClass obj2(3);

    // Using the overloaded operators
    ChallengingClass resultAnd = obj1 & obj2;
    ChallengingClass resultOr = obj1 | obj2;
    ChallengingClass resultXor = obj1 ^ obj2;
    ChallengingClass resultNot = ~obj1;
    ChallengingClass resultLeftShift = obj1 << 2;
    ChallengingClass resultRightShift = obj1 >> 1;
    bool isEqual = (obj1 == obj2);
    bool isNotEqual = (obj1 != obj2);

    std::cout << "Result of AND: " << resultAnd << std::endl;
    std::cout << "Result of OR: " << resultOr << std::endl;
    std::cout << "Result of XOR: " << resultXor << std::endl;
    std::cout << "Result of NOT: " << resultNot << std::endl;
    std::cout << "Result of Left Shift: " << resultLeftShift << std::endl;
    std::cout << "Result of Right Shift: " << resultRightShift << std::endl;
    std::cout << "Is Equal: " << isEqual << std::endl;
    std::cout << "Is Not Equal: " << isNotEqual << std::endl;

    return 0;
}
