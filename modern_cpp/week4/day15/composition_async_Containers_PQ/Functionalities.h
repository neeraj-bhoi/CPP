#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

// #include<bits/stdc++.h>
// #include<array> //STL
#include<unordered_map>
#include<memory>
#include"Car.h"
#include<algorithm>
#include<numeric>
#include<queue>


using CarPointer = std::shared_ptr<Car>;

struct comparator {
    bool operator () (const CarPointer& c1, const CarPointer& c2) const {
        return c1->price() < c2->price();
    }
};

auto comp = [](CarPointer c1, CarPointer c2) {
    return c1->price() < c2->price();
};
using Container = std::priority_queue<CarPointer, std::vector<CarPointer>, comparator>;

void CreateObjects(Container& data);

// void DeleteObjects(const Container& data);

/*
    input : Container
    output : int
*/

void TotalHorsepower1(Container data);


// //is this condition true or false: All cars in the container have a price above 700000
// bool IsContainerAllCarAbove700000(const Container& data);

// //return the Engine pointer of the car whose price is lowest
// // if multiple car instances have the same minimum, consider first minimum found.
// Engine* EnginePointerToMinPriceCar(const Container& data);

// //find the average torque for Engines in the car container
// float AverageEngineTorque(const Container& data);

// // a function to print the model name of the car whose _id is passed as a paramener
// std::string FindCarModelById(const Container& data, std::string carId);


#endif // FUNCTIONALITIES_H

