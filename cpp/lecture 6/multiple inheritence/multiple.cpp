#include"multiple.hpp"

////////////////AAAAAAAAAAAAAAAAAAAAAA
A :: A() {
    a = 0;
}

A :: A(int a) {
    this -> a = a;
}

int A :: get_a() {
    return a;
}

//////////////////BBBBBBBBBBBBBBBBBb
B :: B() {
    b = 0;
}

B :: B(int b) {
    this -> b = b;
}

B :: B(int b, int a) {
    this -> b = b;
    this -> a = a;
}

int B :: get_b() {
    return b;
}

int B :: get_a() {
    return a;
}

/////////////////CCCCCCCCCCCCCCCCCc
C :: C() {
    c = 0;
}

C :: C(int c) {
    this -> c = c;
    A::a = 7;     // a is ambiguous here (in both class A and B)****************
}


int C :: get_c() {
    return c;
}


//////////////DDDDDDDDDDd
D :: D() {
    d = 0;
}

D :: D(int d) {
    this -> d = d;
}

int D:: get_d() {
    return d;
}

//////////////EEEEEEEEEEEEEEEEEe

E :: E() {
    e = 0;
}

E :: E(int e) {
    this -> e = e;
}

int E :: get_e() {
    return e;
}
