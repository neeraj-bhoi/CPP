#ifndef SHAPE_HPP
#define SHAPE_HPP
    #include<bits/stdc++.h>
    using namespace std;
class shape{   /////////////////////////////abstract class
    protected:
        double area;
    public:
        // shape();
        virtual void calculate_area() = 0; //////////pure virtual function
        virtual void display() = 0;
        virtual void accept() = 0;
};

class circle : public shape{
    protected:
        int radius;
        // double area;
    public :
        circle();
        circle(int radius);

        int get_radius();
        void set_radius(int radius);
        // double get_area();

        virtual void accept();
        virtual void calculate_area();
        virtual void display();
};

class sphere : public circle{
    protected:
        double volume;
    public:
        sphere();
        sphere(int radius);

        double get_volume();
        void set_volume(double volume);



        virtual void calculate_area();
        void calculate_volume();
        virtual void display();
};

class rectangle : public shape{
    private:
        int length, width;
    public:
        rectangle();
        rectangle(int length, int width);

        int get_length();
        int get_width();
        void set_length(int length);
        void set_width(int width);

        void accept();

        virtual void calculate_area();
        virtual void display();
};

#endif