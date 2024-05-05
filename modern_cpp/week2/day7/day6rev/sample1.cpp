#include<iostream>
#include<functional>
/*
    the actual data type of a lambda is unknown
*/

// class Functional_wrapper {
// private:
//     ...
//     ...
//     f <-------------lanbda is saved to this number

//     operator() {
//         .......
//     }
// };

void Magic(std::function<void(int)> fn){
    fn(10); //this will call the lambda function inside the wrapper
}

int main() {
    auto f1 = [](int number) { std::cout<<number * 10; };

    f1(10); // like a function, overloaded () operators..

    Magic(
        [](int number) { std::cout<<number*10; }
    );

}