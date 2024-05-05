#include<iostream>
#include<list>

void Magic (std::list<int>& data) {
    std::cout<<data.size()<<"\n";
}

void WierdMagic (std::list<int>&& data) {
    std::cout<<data.size()<<"\n";
}

int main() {
    std::list<int> l1 {1, 2, 3, 4, 5};

    Magic(l1);  // call by reference(lvalue reference)

    WierdMagic(std::list<int> {1, 2, 3, 4, 5});   //call by reference(rvalue reference)
    WierdMagic(std::move(l1));  //std::move is required because rvalue reference cannot be bound to lvalue
    /*  uses move symantics     */
}