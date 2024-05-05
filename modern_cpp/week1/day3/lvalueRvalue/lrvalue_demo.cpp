#include<iostream>
#include<vector>

/*
    any form of data that is not preserved in a fixed location in memory
    will dissappear at the ennd of the expression (full expression)
    where it originated.
*/
int main() {
    10; //10 : temporary(rvalue)
    "helooooo:";
    std::vector<int> {1, 2, 3, 4};
    /*
        pr value(purely rvalue)
        temporary values that get created but are not stored anywhere
    */

    int n1;
    int *ptr = &n1;   // lvalue
}

/*
    if anything which has a name given by the user and memory location -> lvalue;
    else -> rvalue;
*/