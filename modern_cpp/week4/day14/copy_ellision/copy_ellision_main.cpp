#include"copy_ellision_Employee.h"
/*
    C language logic : we have created lvalue called e1
        we have copied e1 into emp [should trigger copy]

    cpp language : we are creating lvalue called e1,
        we are copying e1 by triggering copy constructor of employee class to generate emp!
        eg. Employee emp(e1);

    Modern CPP : we have constructed e1 in the stack memory of Magic,
        now, we need to either move (first priority) into main or copy e1 into main
        [based on whether move is available or not]


    from CPP17 copy_ellision is by default in compiler..
*/

Employee Magic() {
    Employee e1( "harshit", 78080.0f, "Trainer", 10);

    return e1;
}

int main() {
    Employee emp ;
    emp = Magic();    
    std::cout<< emp << "\n";
}
