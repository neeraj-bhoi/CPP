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
        Distance(Distance &d) {
            this -> meter = d.meter;
            this -> centimeter = d.centimeter;
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

        //increment with integer operator
        Distance operator + (int x) {
            this -> meter += x;            
            return *this;
        }

        // PRE increment operator
        Distance operator ++ () {
            this -> meter++;            
            return *this;
        }

        // POST increment operator
        Distance operator ++ (int) {
            this -> meter ++;
            return *this;
        }

        // PRE decrement operator
        Distance operator -- () {
            this -> meter--;            
            return *this;
        }

        // POST decrement operator
        Distance operator -- (int) {
            this -> meter --;
            return *this;
        }

        //friend function   operator overloading for (int) + (object) call
        friend Distance operator + (int x, Distance d);

        //this can be done by normal operator overloaded or with friend function overloaded operator
        // friend Distance operator + (Distance d, int x);

        //overloading insterter and extractor;
        friend ostream& operator <<(ostream& osr ,Distance d);
        friend istream& operator >>(istream& osr ,Distance &d);

};

/////friend function
Distance operator + (int x, Distance d) {
    Distance temp;

    temp.meter = d.meter;
    temp.centimeter = d.centimeter;

    temp.meter += x;

    return temp;
}

/*
//friend function  can be sused instead of + operator while calling for (object)+(int)
// Distance operator + (Distance d, int x) {
//     Distance temp;

//     temp.meter = d.meter;
//     temp.centimeter = d.centimeter;

//     temp.meter += x;

//     return temp;
// }
*/


//extractor overloader
ostream& operator <<(ostream& osr, Distance d) {
    osr << d.meter<<" meter "<<d.centimeter<<" centimeter "<<endl;
    return osr;
}


//inserter overloader
istream& operator >>(istream& isr, Distance &d) {
    isr >> d.meter >> d.centimeter;
    return isr;
}



int main() {
    Distance d1(20, 80), d2(10, 40), d3, d4;

    // d1.display();
    // d2.display();

    // d3 = d1 + d2;

    // d4 = d1 - d2;

    // cout<<"\n\nadd  ";

    // d3.display();
    // cout<<"\n\nsubtract  ";
    // d4.display();

////////////////////////////
//increment and dercrement
////////////////////////////

    // Distance d5;
    // d5 = d1--;
    // d5.display();

    // d5 = --d1;
    // d5.display();

/////////////////////////////
//(int)+(object) or vica versa
/////////////////////////////


    // //for this friend function is used. to call (int) + (object)
    // Distance d5;
    // d5 = 5 + d1;
    // d5.display();

    // //this can be done by normal operator overloaded or with friend function overloaded operator
    // d5 = d1 + 6;
    // d5.display();
   

////////////////////
//extractor and inserter
/////////////////////////

    Distance d6;
    cin>>d6;
    cout<<d6;

    return 0;
}