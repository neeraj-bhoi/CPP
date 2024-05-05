#include<iostream>
/*
    accept infinite parameters
    add 1 parameter with ramaining
*/

template<typename... T>
auto add(T... n1) {
    return (n1 + ...);        //right associative operation
}

template<typename... A>
auto Subtract(A... arg) {
    return (arg - ...);     //  ( 10 - ( 20 - ( 30 - 40)))  right associative  operation
    // return (... - arg);     //  (((( 10 - 20) - 30 ) - 40)  left associative operation
}

template<typename ...R>
void print(R... n) {
    ((std::cout<<n),...);
}


int main() {
    std::cout<< add<int>(10, 20)<<"\n"; 
    std::cout<< add<float>(10.21f, 10.23f) <<"\n"; 
    std::cout<< add(10, 20, 30, 40, 50)<<"\n"; 
    std::cout<< add<int>(100);

    print(19, "hello", 78);

}