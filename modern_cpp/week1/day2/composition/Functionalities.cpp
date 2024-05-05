#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

void CreateObjects(Container &data)
{
    data[0] = new Car(
        "c101",
        1000000.0f,
        "Dzire",
        new Engine(
            300,
            110.0
        ),
        CarType::SEDAN
    );

    data[1] = new Car(
        "c102",
        200000.0f,
        "Honda city",
        new Engine(
            400,
            220.0
        ),
        CarType::HATCHBACK
    );

    data[2] = new Car(
        "c103",
        300000.0f,
        "amaze",
        new Engine(
            500,
            330.0
        ),
        CarType::SUV
    );

}

void DeleteObjects(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty");
    }

    for(Car* c: data) {
        delete c->engine(); //due to 
        delete c;
    }
}

int TotalHorsepower(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty");
    }

    float total = 0.0f;

    for(Car* c: data) {
        total += c->engine()->horsepower();
    }

    return total;
}

bool IsContainerAllCarAbove700000(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty");
    }

    for(Car* c:data) {
        if(c->price() <= 700000) {
            return false;
        }
    }

    return true;    //reaching this point means, no car has price below 7 lakh
}

Engine *EnginePointerToMinPriceCar(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty");
    }

    //assume first data as min
    float min_price = data[0]->price();
    Engine* e = data[0]->engine();

    for(Car* c: data) {
        if(c->price() < min_price) {
            min_price = c->price();
            e = c->engine();
        }
    }

    return e;
}

float AverageEngineTorque(const Container &data)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty");
    }

    // int arr[] = {1, 2, 3, 4};
    // Engine e1(500, 120.0f);
    // Engine* eptr = new Engine(500, 120.0f);
    // // struct Demo d1 = {90, 100};
    // // std::

    //in modern cpp initialization can be done universely in {};

    
    float total_value {0.0f};
    for(Car* c: data) {
        total_value += c->engine()->torque();
    }

    return total_value/data.size();
}

std::string FindCarModelById(const Container &data, std::string carId)
{
    if(data.empty()) {
        throw EmptyContainerException("data is empty");
    }

    for(Car* c: data) {
        if(c->id() == carId) {
            return c->model();
        }
    }


    throw IdNotFoundException("id not found");
    // return ;
}
