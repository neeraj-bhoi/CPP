/*
employee class as base class
*/
#ifndef EMP_HPP
#define EMP_HPP
    #include<bits/stdc++.h>
    using namespace std;

class employee {               //base class
    // string name;
    char* name;

    protected:
        float salary;

    public:
        //constructors
        employee();
        employee(char* name, float salary);
        employee(const employee& e);

        //getters and setters
        void set_name(char* name);
        char* get_name();
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
        manager(char* name, float salary, float hra);
        manager(const manager&);

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
    char* region;

    public:
        general_manager();
        general_manager(char* name, float salary, float hra, char* region);
        general_manager(const general_manager&);
        void display();
};

#endif