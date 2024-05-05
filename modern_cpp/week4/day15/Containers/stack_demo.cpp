/*
    A situation where only one element needs to be accessed and it is most recent 
    item inserted into the containe

    e.g -> A compiler executing function calls

    f1() {
        f2()
    }

    call stack
    f1()<----------recently added, top most entry. will be accessed first!
    f1()<----------still pending...


    * there are no iterators for stack,
    * so cannot loopover the stack
*/

#include<stack>
#include"Employee.h"
#include"Functionalities.h"

using Container = std::stack<Employee>;

void CreateEmployees(Container& data) {
    data.push(
        Employee("harshit", 56000.0f, "Trainer", 10)
    );

    data.push(
        Employee("harshit", 66000.0f, "Trainer", 10)
    );

    data.push(
        Employee("harshit", 76000.0f, "Trainer", 10)
    );
}


int main() {
    Container s1;
    CreateEmployees(s1);
}