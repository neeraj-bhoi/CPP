#ifndef STUD_H
#define STUD_H
    #include<bits/stdc++.h>
    using namespace std;

    class customer;
    class date;
    class bill;

    class customer {
        char* customer_name;

        public:
            customer();
            customer(char* name);
            customer(customer &c);
            void get_name();
            char* set_name();
            friend ostream& operator << (ostream& osr, customer c);
            ~customer();
    };

    class date {
        int day;
        int month;
        int year;

        public:
            date();
            date(int day, int month, int year);
            void get_day();
            void get_month();
            void get_year();
            int set_day(int day);
            int set_month(int month);
            int set_year(int year);
            friend ostream& operator << (ostream& osr, date d);
    };

    class bill {
        int bill_no;
        customer customer_info;
        date bill_date;
        int bill_amount;

        public:
            bill();
            bill(int billno, customer customer_info, date bill_date, int bill_amount);
            void get_bill_amount();
            int set_bill_amount(int bill_amount);
            friend ostream& operator << (ostream& osr, bill b);
    };


#endif 
