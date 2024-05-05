#include"Employee.h"
#include<functional>

/*
    (1) the middlemen/intermediate functions will have to be designed to accept 0 
        or more argument(potentially infinite)

    (2) lvalue binding to rvalue situation is annoying!
*/


template<typename T, typename ...Args>
void Relay(T a, Args... args) {          //only takes args and forwards to another function
    a(std::forward<Args>(args)...);
}


void Magic(int&& n1) {
    /*
        10 gets assigned to n1. now n1 is lvalue.
        forwarding n1 to any function will now forward n1 as lvalue rather than rvalue.
    */
   std::cout<<"hello here i am....."<< n1;
}

int main() {
    // Magic(10);  //10 is rvalue in the scope of main

    Relay<std::function<void(int&&)>, int&&>(Magic, 10);

}