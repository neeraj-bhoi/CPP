#ifndef CAR_H
#define CAR_H

#include<iostream>
#include"Engine.h"
#include "CarType.h"

class Car
{
private:
    std::string _id;
    float _price;
    std::string _model;
    Engine* _engine;    //car contains engine
    CarType _type;

public:
    Car() = delete;
    Car(const Car&) = delete;
    Car(Car&&) = delete;
    Car& operator=(const Car&) = delete;
    Car&& operator=(Car&&) = delete;
    ~Car() {}

    //parametrized constructors
    Car(std::string id, float price, std::string model, Engine* engine, CarType ctype);
    Car(std::string id, std::string model, Engine* engine, CarType ctype);

    //getter setters
    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    Engine* engine() const { return _engine; }
    void setEngine(Engine* engine) { _engine = engine; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    // <<
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    
};

#endif // CAR_H
