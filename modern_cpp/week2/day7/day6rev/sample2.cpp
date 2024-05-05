/*
    objective: Create an adaptor which takes 
        1)  a callable of the following signature
            input : int and int
            output : void
        2)integer number n1
        3)integer number n3

        the adaptor must apply/map the callable on the 2) and 3) integer
*/

#include<iostream>
#include<functional>
/*
    //honda : login --> "something must happen after successful login"
    
    void addition(int n1, int n2) {
        std::cout<<n1+n2;
    }    
*/
/*
    adapter is a higher order function, that accepts
        a)a function wrapper for all functions that have the following signature
            1)int, int input parameters
            2)vois as return type
        b)2 integers by value
*/
void Adapter (std::function<void(int, int)> fn, int n1, int n2) {
    fn(n1, n2);
}

void f1(int n1, int n2) {
    std::cout<<n1*100*n2<<"\n";
}
int main() {
    // Adapter(
    //     [](int n1, int n2) {return n1 * n2;}, //if type does not match {dont do this}
    //     10,                                                  ***********************
    //     20
    // );

    Adapter(
        f1,
        10,
        20
    );

    Adapter(
        [](int n1, int n2) {std::cout<< n1 * n2<<"\n";},
        10,
        20
    );


    Adapter(
        [](int n1, int n2) {std::cout<< n1 - n2;},
        10,
        20
    );
}