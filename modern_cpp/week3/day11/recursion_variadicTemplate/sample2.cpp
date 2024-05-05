/*
    variadic templates      //templates + recursion

    
*/

#include<iostream>

// int add(int n1, int n2) {
//     return n1 + n2;
// } 

template<typename T>
T add(T n1) {
    return n1;
}

// template<typename T>
// T add(T n1, T n2) {
//     return n1 + n2;
// }

template<typename T, typename... Remaining>
auto add(T n1, Remaining... args) {
    return n1 + add(args...);
}

void print() {

}

template<typename T1, typename... T2>
void print(T1 t1, T2... t2){
    std::cout<<t1;
    print(t2...);
}


int main() {
    // std::cout<< add<int>(10, 20) <<"\n";               // creates add function for type int.
    // std::cout<< add<float>(10.21f, 10.23f) <<"\n";     // creates add function for type float
    // std::cout<< add<int>(10, 20, 30, 40, 50) <<"\n";    //creates add function for multiple arguments
    // std::cout<< add<int>(100);

    print(1, 2, 3, 4, 5, 6);
}

