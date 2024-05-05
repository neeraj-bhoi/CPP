#include"details.h"


//customer class


customer::customer(){}

customer::customer(char* name) {
    this -> customer_name = name;
}

customer::customer(customer &c) {
    this -> customer_name = c.customer_name;
}

ostream& operator << (ostream& osr, customer c) {
    osr << "customer name = "<<c.customer_name<<endl;
    return osr;
}

customer::~customer() {
    delete customer_name;
}


//date class


date::date(){}

date::date(int day, int month, int year){
    this -> day = day;
    this -> month = month;
    this -> year = year;
}

ostream& operator << (ostream& osr, date d){
    osr << "day :" << d.day << "month :" << d.month << "year :" << d.year << endl;
    return osr;
}


//bill class


bill::bill(){}
bill::bill(int billno, customer customer_info, date bill_date, int bill_amount){}
ostream& operator << (ostream& osr, bill b){}



int main() {
    customer c("neeraj");
    cout<<c;

    return 0;
}