/*
    smart pointers : wrappers around raw pointers to allow better memory management using RAII cdesign pattern

    1) shared pointer
    2) unique pointer
    3) weak pointer | stalker pointer [shared pointer ---> token]
*/



#include"Employee.h"
#include<iostream>
#include<memory>
#include<thread>

std::shared_ptr<Employee> sptr = std::make_shared<Employee>("harshit", 67000.0f, "trainer", 10);
void Magic(std::shared_ptr<Employee> owner2) {
    // std::this_thread::sleep_for(std::chrono::seconds());
    std::cout<< *owner2 <<"\n";
}

int main() {

    Magic(std::move(sptr));
    std::weak_ptr<Employee> wkptr = sptr;


    if(wkptr.lock()) {
        std::cout<< "owner zinda hai.\n";
    } else {
        std:: cout<< "owner to gaya.\n";
    }

    sptr.reset();
    // std::this_thread::sleep_for(std::chrono::seconds(5));

    if(wkptr.lock()) {
        std::cout<< "owner zinda hai.\n";
    } else {
        std:: cout<< "owner to gaya.\n";
    }
}
