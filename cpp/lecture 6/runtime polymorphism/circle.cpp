#include"circle.hpp"

//////////////////////////        circle
circle :: circle() {
    radius = 1;
}

circle :: circle(int radius) {
    this -> radius = radius;
}

int circle :: get_radius() {
    return radius;
}

double circle :: get_area() {
    return area;
}

void circle :: set_radius(int radius) {
    this -> radius = radius;
}

void circle :: set_area(double area) {
    this -> area = area;
}

void circle :: calculate_area() {
    area = 3.14 * radius * radius;
}

void circle :: display() {
    cout<<" radius = "<<radius<<" area = "<<area<<endl;
}


////////////////////////////////////////////        sphere

sphere :: sphere() : circle() {}


sphere :: sphere(int radius) :circle(radius) {}

double sphere :: get_volume() {
    return volume;
}

void sphere :: calculate_area() {
    // area = 4 * 3.14 * radius * radius;
    double area = 4 * 3.14 * get_radius() * get_radius();
    this -> set_area(area);
}

void sphere :: calculate_volume() {
    volume = 4 / 3 * 3.14 * get_radius() * get_radius() * get_radius();
}


void sphere :: display() {
    cout<<" radius = "<<get_radius()<<" area = "<<get_area()<<" volume = "<<get_volume()<<endl;
}
