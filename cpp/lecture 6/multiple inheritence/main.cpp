#include"multiple.cpp"

int main() {
    A a1(10);
    B b1(20, 33);
    C c1(30);
    D d1(40);
    E e1(50);

    cout<<"a = "<<a1.get_a()<<endl;
    cout<<"b = "<<b1.get_b()<<"   a = "<<b1.get_a()<<endl;
    cout<<"c = "<<c1.get_c()<<"   a = "<<c1.A::get_a()<<endl;
    cout<<"d = "<<d1.get_d()<<"   a = "<<d1.A::get_a()<<endl;
    cout<<"e = "<<e1.get_e()<<"   a = "<<e1.A::get_a()<<endl;


    return 0;
}