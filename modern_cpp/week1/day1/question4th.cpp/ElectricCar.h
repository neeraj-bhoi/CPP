#ifndef ELECTRICElectricCar_H
#define ELECTRICElectricCar_H
    #include"Car.h"
#include <ostream>

class ElectricCar : public Car
{
private:
    /* data */
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

    float Drive() override;     // override checks if overriden perfectly or not...
    void ShowElectriCarDetails();

    //getters and setters
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

#endif // ELECTRICElectricCar_H
