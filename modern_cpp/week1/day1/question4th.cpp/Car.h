#ifndef CAR_H
#define CAR_H
#include<iostream>

class Car
{
private:
    /* data */
    std::string _name {""}; //default initialisation
    int _acceleration {0};
    int _top_speed {0};
    float _ex_showroom_price {0.0f};

public:

    ///* default and disabled constructors and destructors*/

    Car(/* args */) = default;  //default constructor enable {default constructor}
    Car(const Car&) = delete;   // disabled copy constructor {copy constructor}
    Car(Car&&) = delete;        // disabled move constructor {move constructor}     [BRAND NEW]
    Car& operator=(const Car&) = delete;    //disabled copy assignment operator
    Car& operator=(Car&&) = delete;         //disabled copy move assignment     [BRAND NEW]

    Car( std::string name, int acceleration, int top_speed, float price);   //parametrized constructor

    virtual ~Car() = default;   //destructor enabled

    //getters and setters;
    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    int topSpeed() const { return _top_speed; }
    void setTopSpeed(int top_speed) { _top_speed = top_speed; }

    float exShowroomPrice() const { return _ex_showroom_price; }
    void setExShowroomPrice(float ex_showroom_price) { _ex_showroom_price = ex_showroom_price; }

    // <<  
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    virtual float Drive() = 0;
     

};

#endif // CAR_H
