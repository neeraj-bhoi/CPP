#ifndef MULTIPLE_HPP
#define MULTIPLE_HPP
    #include<bits/stdc++.h>
    using namespace std;

class A {
    protected:
    int a;
    public:
        A();
        A(int a);
        int get_a();
};


class B{
    int b;
    int a;
    public:
        B();
        B(int b);
        B(int b, int a);
        int get_b();
        int get_a();
};

class C : virtual public A, public B{
    int c;
    public:
        C();
        C(int c);
        int get_c();
};

class D : virtual public A {
    int d;
    public:
        D();
        D(int d);
        int get_d();
};

class E : public C, public D{
    int e;
    public:
        E();
        E(int e);
        int get_e();
};

#endif