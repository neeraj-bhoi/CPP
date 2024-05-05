/*
    inheritence hierarchy of circle class
*/
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
    #include<bits/stdc++.h>
    using namespace std;

class circle {
    // protected:
        int radius;
        double area;
    public:
        circle();
        circle(int radius);

        //getter setters
        int get_radius();
        void set_radius(int radius);
        double get_area();
        void set_area(double area);

        //polymorphic function
        virtual void calculate_area();
        virtual void display();
};

class sphere :public circle{
    double volume;
    public:
        sphere();
        sphere(int radius);

        //getter setters
        double get_volume();


        //polymorphic function - overriden member function
        virtual void calculate_area();
        virtual void calculate_volume();

        virtual void display();


};



#endif