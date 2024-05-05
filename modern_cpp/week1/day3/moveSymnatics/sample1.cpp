#include<iostream>
#include<vector>

/*
    numbers passed to magic must always be temporary value or moved value

    capture parameter by rvalue reference
*/
void Magic(std::vector<int> &&data) {

}

int main() {
    std::vector<int> value {10, 20, 30, 40, 50};

    Magic(std::move(value));

    std::cout<<value.size();
}

/*
    we create vector in main(scope in main)
    HEAP
        [10, 20, 30, 40, 50 |   |   |   |   |   |   ]
        ^                  ^                        ^
        |                  |                        |
        |                  |                        |
        
        [0x100H]        [0x116H]                [0x132H]
        <---------------------main------------------->
        <---------------------24 bytes--------------->

*/

/*PROGRESS
    1)programs starts because of schedules the process
    2) main function is executed as a thread by the OS
    3) vecotor of integer values is created in the scope of main
        a)Heap allocation happens and vector gets space on heap
        b)pointers to start, end and capacity are recorded in the vector object "value" in main
    4)Magic(std::move(value));
        a) std::move(value) : it converts lvalue into rvalue
            tells the compiler "value" vector can be prepared to move
        b) now vector value is treated as an rvalue.
            so Magic(std::move(value)) becomes Magic(std::vector<int> {10, 20, 30, 40, 50} )   *****
*/