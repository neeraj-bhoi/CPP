/*
employee class as base class
*/
#ifndef EMP_HPP
#define EMP_HPP
    #include<bits/stdc++.h>
    using namespace std;

class employee {               //base class
    string name;

    protected:
        float salary;

    public:
        //constructors
        employee();
        employee(string name, float salary);

        //getters and setters
        void set_name(string name);
        string get_name();
        void set_salary(float salary);
        float get_salary();

        //destructor
        ~employee();
};


//derived class
//  class < derived class > : < access specifier > < base class >
class manager : public employee {
    float hra;

    public: 
        //constructors
        manager();
        manager(string name, float salary, float hra);

        //getters and setters
        void set_hra(float hra);
        float get_hra();
        void display();

        // business logic
        void calculate_slary();

        //destructor
        ~manager();
};

class general_manager : public manager{
    string region;

    public:
        general_manager();
        general_manager(string name, float salary, float hra, string region);
        void display();
};

#endif