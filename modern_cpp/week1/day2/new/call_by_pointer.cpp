#include<iostream>

/*
    int &a :: reference
    &a     :: no data type to the left of a : (address pointer)
*/

void Magic(int * value) {         // call by pointer

    std::cout<<"dereferencing before modification data gives : " << *value<<"\n";
    std::cout << "content of value Magic b4 modification is : "<< value << "\n";
    std::cout << "address of value inside Magic : "<< &value << "\n";

    *value = 111;
    std::cout << "content of value of magic after modification : "<< value << "\n";

    std::cout<<"dereferencing after modification data gives : " << *value<<"\n";
}

int main() {
    int value = 100;
    std::cout << "value in Main b4 modification is : "<< value << "\n";
    std::cout << "address of value inside Main  : "<< &value << "\n";
    Magic(&value); //pass address/pointer
    std::cout << "value in main after function call : "<< value << "\n";

    return 0;
}