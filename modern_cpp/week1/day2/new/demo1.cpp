#include<iostream>
using namespace std;

struct Employee {
    int _id;
    char _grade;

    void display() {
        std::cout<<"omg!!!!"<<"\n";
    }
};

int main() {
    struct Employee e1 {181, 'A'};
}