#include<iostream>
#include<functional>

class Action
{
private:
    int _id;
public:
    Action(/* args */) = default;
    ~Action() = default;
    Action(int n) {
        _id = n;
    }

    void Operation(int number) {
        std::cout<< _id * number;
    }
};

int main() {
    Action a1(10);
    auto binded_Operation = std::bind(&Action::Operation, &a1, std::placeholders::_1);
    //                             <------------------------------>

    binded_Operation(40);   //a1.Operation(40);
}

/*
    swapping parameters
    fixing parameters
    extra
    lambda
    member fn
*/