#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class A{
public:
    int *mp = nullptr;
    A() {
        this -> mp = nullptr;
    }
    A(int a) {
        this -> mp = &a;
        // free(a);
    }
    A(const A &a) {
        *this -> mp = *a.mp;
    }


};

int main()
{
    // cout << "Hello World!" << endl;

    A a(5);
    A b(a);

    cout<<*a.mp<<" "<<*b.mp;

    return 0;
}
