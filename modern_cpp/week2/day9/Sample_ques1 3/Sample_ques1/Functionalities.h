#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "TouristVehicle.h"
#include <vector>

using PermitContainer = std::vector<Permit *>;
using TouristContainer = std::vector<TouristVehicle *>;

void CreateObject(PermitContainer& Pdata, TouristContainer &Tdata);

// function to return first n instance of touristVehicle with conditions.
TouristVehicle *Find_n_instances(TouristContainer &Tdata, int n);

// find and return average per hour booking charge
float Avg_BookingCharge(TouristContainer &Tdata, int n);

// find tourist Veichle which has maximum per hour booking charge
std::string Max_PerHour_BookingCharge(TouristContainer &Tdata);

// function to return first n Tourist vehicle instance
void print_n_instanecs(TouristContainer &Tdata, int n);

void DeleteObject(TouristContainer &Tdata, PermitContainer& Pdata);

#endif // FUNCTIONALITIES_Hbooking
