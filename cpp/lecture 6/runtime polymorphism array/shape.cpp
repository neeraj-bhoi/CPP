#include"shape.hpp"

circle :: circle() {
    radius = 0;
}

circle :: circle(int radius) {
    this -> radius = radius;
}

int circle :: get_radius() {
    return radius;
}

void circle ::set_radius(int radius) {
    this -> radius = radius;
}

void circle :: accept() {
    cout<<"enter radius : ";
    cin>>radius;
    cout<<endl;
}

void circle :: calculate_area() {
    area = 3.14 * radius * radius;
}

void circle :: display() {
    cout<<" area of circle = "<<area<<" and radius = "<<radius<<endl;
}


/////////////////////////   sphere

sphere :: sphere () : circle(){}

sphere :: sphere (int radius) : circle (radius){}

double sphere :: get_volume() {
    return volume;
}

void sphere :: set_volume(double volume) {
    this -> volume = volume;
}

void sphere :: calculate_area() {
    area = 4 * 3.14 * radius * radius;
    volume = (area * radius) / 3;
}

void sphere :: display() {
    cout<<" area of sphere = "<<area<<" and radius = "<<radius<<" and volume = "<<volume<<endl;
}

//////////////////////////rectangle

rectangle :: rectangle() {
    length = 0;
    width = 0;
}

rectangle :: rectangle(int length, int width) {
    this -> length = length;
    this -> width = width;
}

int  rectangle :: get_length() {
    return length;
}

int rectangle ::  get_width() {
    return width;
}

void rectangle :: set_length(int length) {
    this -> length = length;
}

void rectangle :: set_width(int width) {
    this -> width = width;
}

void rectangle :: accept() {
    cout<<" enter length and width of rectangle = ";
    cin>> length;
    cin>> width;
    cout<<endl;
}

void rectangle:: calculate_area() {
    area = length * width;
}

void rectangle :: display() {
    cout<<"area of rectangle = "<<area<<" and length = "<<length<<" and width = "<<width<<endl;
}
