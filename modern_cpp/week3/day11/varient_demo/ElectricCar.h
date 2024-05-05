#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include<iostream>
#include<vector>


class ElectricCar
{
private:
    /* data */
    std::string _name {""}; //default initialisation
    int _acceleration {0};
    int _top_speed {0};
    float _ex_showroom_price {0.0f};

    int _battery_capacity {0};
    float _time_to_charge {0.0f};       
    float _motor_power {0.0f};
    float _max_power {0.0f};
    float _range {0.0f};
public:
    ElectricCar() = default;  //default constructor enable {default constructor}
    ElectricCar(const ElectricCar&) = delete;   // disabled copy constructor {copy constructor}
    ElectricCar(ElectricCar&&) = delete;        // disabled move constructor {move constructor}     [BRAND NEW]
    ElectricCar& operator=(const ElectricCar&) = delete;    //disabled copy assignment operator
    ElectricCar& operator=(ElectricCar&&) = delete;         //disabled copy move assignment     [BRAND NEW]
    ElectricCar(std::string name, int acceleration, int top_speed, float price, int battery_capacity, float time_to_charge, float motor_power, float max_power, float range);
    ~ElectricCar() = default;

    float Drive();     // override checks if overriden perfectly or not...
    void ShowElectriCarDetails();

    //getters and setters
    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    int topSpeed() const { return _top_speed; }
    void setTopSpeed(int top_speed) { _top_speed = top_speed; }

    float exShowroomPrice() const { return _ex_showroom_price; }
    void setExShowroomPrice(float ex_showroom_price) { _ex_showroom_price = ex_showroom_price; }

    int batteryCapacity() const { return _battery_capacity; }
    void setBatteryCapacity(int battery_capacity) { _battery_capacity = battery_capacity; }

    float timeToCharge() const { return _time_to_charge; }
    void setTimeToCharge(float timeToCharge) { _time_to_charge = timeToCharge; }

    float motorPower() const { return _motor_power; }
    void setMotorPower(float motor_power) { _motor_power = motor_power; }

    float maxPower() const { return _max_power; }
    void setMaxPower(float max_power) { _max_power = max_power; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);
};


std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs) {
    os << "_name: " << rhs._name
       << " _acceleration: " << rhs._acceleration
       << " _top_speed: " << rhs._top_speed
       << " _ex_showroom_price: " << rhs._ex_showroom_price
       << " _battery_capacity: " << rhs._battery_capacity
       << " time_to_charge: " << rhs._time_to_charge
       << " _motor_power: " << rhs._motor_power
       << " _max_power: " << rhs._max_power
       << " _range: " << rhs._range<<std::endl;
    return os;
}

ElectricCar::ElectricCar(std::string name, int acceleration, int top_speed, float price, int battery_capacity, float time_to_charge, float motor_power, float max_power, float range)
    : _name{name}, _acceleration{acceleration}, _top_speed{top_speed}, _ex_showroom_price{price}, _battery_capacity(battery_capacity),
    _time_to_charge(time_to_charge), _motor_power(motor_power), _range(range), _max_power(max_power) 
{}

float ElectricCar::Drive()
{
    return 0.0f;
}

void ElectricCar::ShowElectriCarDetails()
{
    std::cout << "_name: " << _name
       << " _acceleration: " << _acceleration
       << " _top_speed: " << _top_speed
       << " _ex_showroom_price: " << _ex_showroom_price
       << " _battery_capacity: " << _battery_capacity
       << " time_to_charge: " <<_time_to_charge
       << " _motor_power: " <<_motor_power
       << " _max_power: " <<_max_power
       << " _range: " << _range <<std::endl;
}

#endif // ELECTRICCAR_H
