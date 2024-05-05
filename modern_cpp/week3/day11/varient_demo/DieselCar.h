#ifndef DIESELCAR_H
#define DIESELCAR_H

#include<iostream>
#include<string>


class DieselCar
{
private:
    std::string _name {""}; //default initialisation
    int _acceleration {0};
    int _top_speed {0};
    float _ex_showroom_price {0.0f};

    float _fuel_capacity {0};
    float _mileage {0};
    float _motor_power {0};

public:
    DieselCar() = default;  //default constructor enable {default constructor}
    DieselCar(const DieselCar&) = delete;   // disabled copy constructor {copy constructor}
    DieselCar(DieselCar&&) = delete;        // disabled move constructor {move constructor}     [BRAND NEW]
    DieselCar& operator=(const DieselCar&) = delete;    //disabled copy assignment operator
    DieselCar& operator=(DieselCar&&) = delete;         //disabled copy move assignment     [BRAND NEW]
    DieselCar(std::string name, int acceleration, int top_speed, float price, float fuel_capacity, float mileage, float motor_power);
    ~DieselCar() = default;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    int topSpeed() const { return _top_speed; }
    void setTopSpeed(int top_speed) { _top_speed = top_speed; }

    float exShowroomPrice() const { return _ex_showroom_price; }
    void setExShowroomPrice(float ex_showroom_price) { _ex_showroom_price = ex_showroom_price; }

    void ShowDieselCarDetails();

    float fuel_capacity() const { return _fuel_capacity; }
    void setFuel_capacity(const float &fuel_capacity) { _fuel_capacity = fuel_capacity; }

    float mileage() const { return _mileage; }
    void setMileage(const float &mileage) { _mileage = mileage; }

    float motor_power() const { return _motor_power; }
    void setMotor_power(const float &motor_power) { _motor_power = motor_power; }
    
    friend std::ostream &operator<<(std::ostream &os, const DieselCar &rhs);
};


DieselCar::DieselCar(std::string name, int acceleration, int top_speed, float price, float fuel_capacity, float mileage, float motor_power)
    : _name{name}, _acceleration{acceleration}, _top_speed{top_speed}, _ex_showroom_price{price}, _fuel_capacity{fuel_capacity}, _mileage{mileage}, _motor_power{motor_power}
{}

void DieselCar::ShowDieselCarDetails()
{
    std::cout << "_name: " << _name
       << " _acceleration: " << _acceleration
       << " _top_speed: " << _top_speed
       << " _ex_showroom_price: " << _ex_showroom_price
       << " _battery_capacity: " << _fuel_capacity
       << " time_to_charge: " <<_mileage
       << " _motor_power: " <<_motor_power << std::endl;
}

std::ostream &operator<<(std::ostream &os, const DieselCar &rhs) {
    os << "_name: " << rhs._name
       << " _acceleration: " << rhs._acceleration
       << " _top_speed: " << rhs._top_speed
       << " _ex_showroom_price: " << rhs._ex_showroom_price
       << " _battery_capacity: " << rhs._fuel_capacity
       << " time_to_charge: " <<rhs._mileage
       << " _motor_power: " <<rhs._motor_power << std::endl;
    return os;
}

#endif // DIESELCAR_H
