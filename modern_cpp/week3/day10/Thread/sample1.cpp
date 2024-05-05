/*

    codes written till now : SINGLE THREAD, SINGLE PROCESS, SYNCHRONOUS PROGRAMS!

    processor : It is a hardware device based on SILICON (at least till today) which executes instructions given
        eg. Intel i5 12 gen 1230U

    core : section of processor which is capable of executing one whole process
    
    DELAYS : i/o delays , CPU-bound delay....
*/


#include<iostream>
#include<array>
#include<thread>

void Square(std::array<int, 5>& data) {
    for(int number : data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));   //1 second artificial delay
        std::cout<<"square of number : "<<number <<" is : "<<number * number<<"\n";
    }
}

void Cube(std::array<int, 5>& data) {
    for(int number : data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));   //1 second artificial delay
        std::cout<<"Cube of number : "<<number <<" is : "<<number * number * number<<"\n";
    }
}

int main() {
    std::array<int, 5> data {1, 2, 3, 4, 5};
    Square(data);
    Cube(data);
}