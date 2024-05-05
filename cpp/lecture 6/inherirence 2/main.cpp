/* 
    to demonstrate class inheritence
*/
#include"emp.cpp"

int main() {
    employee e1;
    manager m1;

    // e1.set_name("BBBBBBBBBBBBBBBBBBBBB");

    cout<<e1.get_name()<<"  "<<e1.get_salary()<<endl;
    cout<<m1.get_name()<<"  "<<m1.get_salary()<<"  "<<m1.get_hra()<<endl;

    employee e2("vijay", 20000);
    manager m2("ajay", 22000, 3000);

    // m2 = m1;

    cout<<e2.get_name()<<"  "<<e2.get_salary()<<endl;
    float s = m2.get_salary();
    m2.calculate_slary();
    // cout<<m2.get_name()<<"  "<<m2.get_salary()<<"  "<<m2.get_hra()<<endl;
    m2.display();

    general_manager g1("dhananjay", 30000, 5000, "east");
    g1.display();

    general_manager g2 = g1;
    g2.display();

    return 0;
}


/*

*public inheritence
    all public members of base class becomes public members of the derived class
    all protcted members of the base class becomes protected members of the derived class

*protected inheritence
    all protected and public members of the base class becomes protected members of the derived class

*public inheritence
    all public and protected members of the base class becomes public mambers of the derived class
*/