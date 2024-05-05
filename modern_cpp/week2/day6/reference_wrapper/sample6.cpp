#include<iostream>
#include<functional>

void Magic(int& ref) {

}

int main() {
    int data {10};
    std::reference_wrapper<int> refWrap {data}; //must refer lvalue
        
    Magic(refWrap); //it can convert to normal reference implicitely.

    std::reference_wrapper<int> arr[] {refWrap};
}