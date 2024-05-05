#include"circle.cpp"

int main() {
    // circle c1(10);
    // sphere s1(100);

    // c1.calculate_area();
    // c1.display();               //polymorphic function(static)

    // s1.calculate_area();
    // s1.calculate_volume();

    // s1.display();               //polymorphic function(static)



    /*
            dyanamic polymorphism
                1.  binding
                2.  pyanamic binding
                3.  inheritence hierarchy
                4.  pase class pointer
                5.  polymorphic member function(overriden member function)
        */

       //base class pointer

       circle *cp1 = NULL;

       cp1 = new circle(10);
    //    cp1 -> calculate_area();
    //    cp1 -> display();

       cp1 = new sphere(10);
       cp1 -> calculate_area();
    //    cp1 -> calculate_volume();
        ((sphere *) cp1) -> calculate_volume();
       cp1 -> display();


    //    sphere *cp1 = NULL;

    //    cp1 = new sphere(100);
    //    cp1 -> calculate_area();
    //    cp1 -> calculate_volume();
    //    cp1 -> display();

    //    (circle*)cp1 = new circle(10);
    //    cp1 -> calculate_area();
    //    cp1 -> display();

}