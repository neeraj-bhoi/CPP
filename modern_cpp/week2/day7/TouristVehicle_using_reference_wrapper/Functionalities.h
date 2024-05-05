#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"TouristVehicle.h"
#include<vector>

using Container = std::vector<std::shared_ptr<TouristVehicle>>;

void CreateObject(Container& data);

#endif // FUNCTIONALITIES_H
