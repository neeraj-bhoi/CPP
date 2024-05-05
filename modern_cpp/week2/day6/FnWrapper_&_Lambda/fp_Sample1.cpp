#include<iostream>

void Square(int number) {
    std::cout<<"Square of "<<number<<" is : "<<number * number<<"\n";
}

void Cube(int number) {
    std::cout<<"Cube of :"<<number<<" is : "<<number * number * number<<"\n";
}

//Higher order function
//either accepts/returns/both another function
void operation(int* arr, int size, void(ptr)(int)) {
    for(int i = 0; i < size; i++) {
        (ptr)(arr[i]);
    }
}

int main() {
    //fn pointer
    // void (*ptr)(int) = Square;    //address of function
    // void (*ptr)(int) = Cube;

    int arr[5] = {10, 20, 30, 40, 50};
    operation(arr, 5, Square);      //signature of function passed and parameters should match perfectly
}



/*
    Higher Order Functions
    Anonymous functions
    Functional programming paradigm
    no state
    immutable data
    currying
    First-class function
*/