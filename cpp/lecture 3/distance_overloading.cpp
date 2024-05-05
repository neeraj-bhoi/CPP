#include<bits/stdc++.h>
using namespace std;

class Distance {
    int meter;
    int centimeter;

public :
    Distance() {
        meter = 0;
        centimeter = 0;
    }
    Distance(int meter, int centimeter) {
        this -> meter = meter;
        this -> centimeter = centimeter;
    }
    void display() {
        cout<<meter<<"."<<centimeter<<endl;
    }
    // operator overloading
    Distance operator + (Distance &d) {
        Distance temp;
        temp.meter = this -> meter + d.meter;
        temp.centimeter = this -> centimeter + d.centimeter;
        temp.meter += (temp.centimeter / 100);
        temp.centimeter %= 100;
        return temp;
    }
    
    Distance operator - (Distance &d) {
        Distance temp;
        temp.meter = this -> meter - d.meter;
        temp.centimeter = this -> centimeter - d.centimeter;
        temp.meter += (temp.centimeter / 100);
        temp.centimeter %= 100;
        return temp;
    }
};

int main() {
    Distance d1(20, 800), d2(10, 400), d3, d4;

    d1.display();
    d2.display();

    d3 = d1 + d2;

    d4 = d1 - d2;

    cout<<"\n\nadd  ";

    d3.display();
    cout<<"\n\nsubtract  ";
    d4.display();

    return 0;
}