// #include <iostream>
// #include<bits/stdc++.h>

// using namespace std;

// struct A{
// public:
//     int *mp = nullptr;
//     A(){};
//     A(int a) {
//         mp = new int(a);
//         cout<<"sz:"<<hex<<(size_t)this<<endl;
//     }
//     A(A& a) {
//         this -> mp = a.mp;
//     }

//     A operator + (A a) {
//         A temp;
//         *(temp.mp) = *(this -> mp) + *(a.mp);
//         return temp;
//     }
//     A operator - (A a) {
//         A temp;
//         *(temp.mp) = *(this -> mp) - *(a.mp);
//         return temp;
//     }

//     ~A() {
//         delete mp;
//     }
// };

// int main()
// {
//     // cout << "Hello World!" << endl;
//     A a(5);
//     A b = a;
//     A c;
//     a = b;

//     c = a + b;
//     cout<<*(a.mp)<<"  "<<*(b.mp)<<"  "<<*(c.mp);
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
// class B{
//     public:
//     B(){
//         cout<<"Constructor called of B"<<endl;
//     }
//     ~B(){
//         cout<<"Destructor called of B"<<endl;
//     }
// };
// class P0: public B{
//     public:
//     P0(){
//         cout<<"P0's constructor will be called"<<endl;
//     }
//     ~P0(){
//         cout<<"P0's destructor will be called"<<endl;
//     }
// };
// class P1: public B{
//     public:
//     P1(){
//         cout<<"P1's constructor will be called"<<endl;
//     }
//     ~P1(){
//         cout<<"P1's destructor will be called"<<endl;
//     }
// };
// class C: public P0,public P1{
//     public:
//     C(){
//         cout<<"C's constructor will be called"<<endl;
//     }
//     ~C(){
//         cout<<"C's destructor will be called"<<endl;
//     }
// };
class B1{
public:
    int a;
    double b;
};
class B2{
public:
    int a;
};
class B3{
public:
    int a;
};
class C:public B1,public B2,public B3{
public:
    int a;
    int c;

    static void *operator new(size_t)
};
int main(){
    // B1 bb,bb1;
    // bb = bb1;
    // B2 bb2;

    // C c;
    // bb = c;
    // B1 *b = &c;
    // B2 *b2 = &c;
    // B3 *b3 = &c;
    // cout<<b<<" "<<b2<<" "<<b3<<" ";
    // cout<<sizeof(b);
    // B1 *b = new B1();
    // cout<<b->a<<" ";

    // B2 *b1 = new B2();
    // cout<<b1->a<<" ";
    // delete b1;
    // delete b;
    // int *arr = new int[20];
    // delete[] arr;
    char *s = (char*)malloc(200);
    void *y = s;
    cout<<"ma:"<<hex<<(size_t)y<<endl;
    B1 *b = new(y) B1();
    B1 c;
    c = c;
    b = &c;
    b->a = 5;
    free(s);
    return 0;

}

