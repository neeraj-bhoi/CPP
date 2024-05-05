#include<iostream>
#include<functional>    //support for functional programming !!!
/*  function wrapper instead of function pointer*/


void Square(int number) {
    std::cout<<"Square of :"<<number<<" is : "<<number * number<<"\n";
}

void Cube(int number) {
    std::cout<<"Cube of :"<<number<<" is : "<<number * number * number<<"\n";
}

//Higher order function
//either accepts/returns/both another function
void operation(int* arr, int size, std::function<void(int)> fn) {   //function wrapper  *******
    for(int i = 0; i < size; i++) {
        fn(arr[i]);
    }
}

int main() {
    //fn pointer

    int arr[5] = {10, 20, 30, 40, 50};
    operation(arr, 5, Square);      //signature of function passed and parameters should match perfectly
}
