#include<iostream>
#include<functional>
#include<array>

/*
    design an adaptor function that accepts a container of function wrappers and a 
    container of data values
    map each function on each item in the data container and print the output 

    all functions must accept only an integer and return void
*/

/*

*/

using fnType = std::function<void(int)>;
using dataContainer = std::array<int, 5>;
using functionContainer = std::array<fnType, 3>;

void Adaptor(const functionContainer& fns, const dataContainer& data) {
    //loop over functions, nested loop over data, apply fn on data
    for(const fnType fn : fns) {
        for(int val : data) {
            fn(val);
        }
        std::cout<<"\n";
    }
}

int main() {
    functionContainer fns {
        [](int number) { std::cout<<number * 10 <<"\n"; },
        [](int number) { std::cout<<number * number <<"\n"; },
        [](int number) { std::cout<<number * number * number <<"\n"; }
    };
    Adaptor(
        fns,
        std::array<int, 5> {1, 2, 3, 4, 5}
    );
}