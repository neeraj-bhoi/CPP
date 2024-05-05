#include<iostream>

/*
    int &a :: reference
    &a     :: no data type to the left of a : (address pointer)
*/

void Magic(int& value) {         // call by reference
    std::cout << "value Magic b4 modification is : "<< value << "\n";
    std::cout << "address of value inside Magic : "<< &value << "\n";
    value = 111;
    std::cout << "value of magic after modification : "<< value << "\n";

}

int main() {
    int value = 100;
    std::cout << "value in Main b4 modification is : "<< value << "\n";
    std::cout << "address of value inside Main  : "<< &value << "\n";
    Magic(value);
    std::cout << "value in main after function call : "<< value << "\n";

    return 0;
}