 /*
 Program : Array of objects
 Program By : Anil Donwade
 Date : 10-01-2024
 */

 #include <iostream>
 using namespace std;

//class definition for the circle entity
class circle{
int radius;
double area;
public:
//constructors
circle(){}
circle(int radius){
this->radius=radius;
}

//getters-setter
int get_radius(){
return radius;
}

void set_radius(int radius){
this->radius=radius;
}

double get_area(){
return area;
}

//logic function
void calc_area(){
area = 3.141592*radius*radius;
}

circle scale_circle(int scale){
return this->radius *=scale;
}

circle double_circle(){
return this->radius <<= 1;
}

//static member function to display all circles
void static display( circle* cptrarr[]){
for( int i=0; i< 3; i++){
cptrarr[i]->calc_area();
cout << cptrarr[i]->get_area() << endl;
}
}

};//end of class

//main() function
int main(){
//declare all circles
circle circle_array[]= { circle(10), circle(20), circle(30)}; //create and61: //initialization
//display all circles
for( circle x: circle_array){
x.calc_area();
cout << x.get_radius() << " " << x.get_area() << endl;
}

//scale the given circle, by 2
circle c(100);
c.scale_circle(2);
c.calc_area();
cout << "Area of circle having radius "<< c.get_radius() << " is " << c.get_area();
//double the size of circle, a special case of scaling by 2
circle nc1 = c.double_circle();
nc1.calc_area();
cout << "Area of circle having radius "<< nc1.get_radius() << " is " << nc1.get_area();
circle *circleptr_array1[4]; //create array of pointers to circ80:
//populate array of circles
circleptr_array1[0]=new circle(11);
circleptr_array1[1]=new circle(22);
circleptr_array1[2]=new circle(33);

//display all circles from the array of pointers to circle objects
circle::display(circleptr_array1);

return 0;
}