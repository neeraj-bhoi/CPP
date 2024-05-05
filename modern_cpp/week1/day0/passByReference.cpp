#include<bits/stdc++.h>
using namespace std;

int fun(int &a, int *b) {
    cout<<"a = "<<a<<"  b = "<<*b;
    return 0;
}

int main() {
    int a = 10;
    int *b = &a;
    b--;

    int c = fun(a, b);

    return 0;
}