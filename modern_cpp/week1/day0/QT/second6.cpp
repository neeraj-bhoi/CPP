#include <iostream>

using namespace std;

// class B{
// public:
//     B() {
//         cout<<"B constructor"<<endl;
//     }
//     ~B() {
//         cout<<"B destructor"<<endl;
//     }
// };

// class p0 : public B{
// public:
//     p0() {
//         cout<<"p0 constructor"<<endl;
//     }
//     ~p0() {
//         cout<<"p0 destructor"<<endl;
//     }
// };

// class p1 : public B {
// public :
//     p1() {
//         cout<<"p1 constructor"<<endl;
//     }
//     ~p1() {
//         cout<<"p1 destructor"<<endl;
//     }
// };

// class c : public p0, public p1{
// public :
//     c() {
//         cout<<"c constructor"<<endl;
//     }
//     ~c() {
//         cout<<"c destructor"<<endl;
//     }
// };

// int main()
// {
//     // cout << "Hello World!" << endl;
//     c c1;
//     return 0;
// }


// class b {
//     int i;
//     int j;
// public:
//     b() {
//         cout<<"b constructor"<<endl;
//     }
// };

// class a0 {
//     int k;
//     int l;
// public:
//     a0() {
//         cout<<"a0 constructor"<<endl;
//     }
// };

// class a1 {
//     int m;
//     int n;
// public:
//     a1() {
//         cout<<"a1 constructor"<<endl;
//     }
// };

// class c : public a0, public a1 {
//     int o;
//     int p;
// public:
//     c() {
//         cout<<"c constructor"<<endl;
//     }
// };


struct A{
    int *mp = nullptr;
    A() {
        mp = new int;
        cout<<"sz:"<<hex<<(size_t)this<<endl;
    }
    ~A() {
        delete mp;
    }
};


int main() {
    // c c;

    // a0 *a00 = &c;
    // a1 *a11 = &c;



    // int *n;
    // n = new int[10];
    // // getchar();
    // for(int i = 0; i < 10; i++) {
    //     n[i] = i;
    //     cout<<n[i];
    // }
    // delete[] n;

    // void *y = malloc(sizeof(A));

    int stac[10];
    void *y = stac;
    cout<<"ma:"<<hex<<(size_t)y<<endl;
    A *a = new(y) A;
    a -> ~A();
    return 0;


}
