#include<iostream>

class A {
    int n;
    public:
    A() {
        n = 10;
    }
    ~A() = default;

    int getN() const { return n; }
    void setN(int n_) { n = n_; }
};

class B {
    int *n;
    public:
    B() {
        *n = 20;
    }
    B(A *a) {
        *n = a->getN();
    }
    ~B() {
        delete n;
    }

    int getN() const { return *n; }
    void setN(int n_) { *n = n_; }
};


int main()
{
    A a;
    B b(&a);
    b.~B();
    std::cout<<a.getN();
    // std::cout<<b.getN();
    return 0;
}