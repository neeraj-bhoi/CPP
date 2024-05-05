/*
    smart pointers : wrappers around raw pointers to allow better memory management using RAII cdesign pattern

    1) shared pointer
    2) unique pointer
    3) weak pointer | stalker pointer [shared pointer ---> token]



    jthread ---------> CPP20
    create the thread in scope and when gets out of scope destructor calls join
*/

/*

*/

#include"Employee.h"
#include<iostream>
#include<memory>
#include<thread>
#include<mutex>

std::mutex mt;
bool allThreadsDone = false;

void ChangeName(std::unique_ptr<Employee>& owner2) {
    std::lock_guard<std::mutex> lg(mt);
    owner2->setName("harshit shukla");
    std::cout<<"ChangeName    ---  "<< *owner2 <<"\n";
}

void UpdateSalary(std::unique_ptr<Employee>& owner3) {
    std::lock_guard<std::mutex> lg(mt);
    owner3->setSalary(770000.0f);
    std::cout<<"UpdateSalary  ---  "<< *owner3 <<"\n";
}

int main() {
    // std::unique_ptr<int[]> ptr1 = std::make_unique<int[]> {.....};

    std::unique_ptr<Employee> ptr = std::make_unique<Employee>("harshit", 670000.0f, "trainer", 10);

    std::thread t1(&ChangeName, std::ref(ptr));
    std::thread t2(&UpdateSalary, std::ref(ptr));

    if(std::lock_guard<std::mutex> lg(mt); !allThreadsDone) {
        std::cout<<"main         ---   "<< *ptr <<"\n";
    }

    t1.join();
    t2.join();

    allThreadsDone = true;
}
