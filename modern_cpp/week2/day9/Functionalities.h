#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<functional>
#include<vector>

using Container = std::vector<int>;
using Fntype = std::function<void(Container&)>;

void Adaptor(Fntype fn, Container& data);

//lambda functions declared here and initialize(not define{because it is an object variable, rather than fnction}) in .cpp
extern Fntype lfn1;
extern Fntype lfn2;
extern Fntype lfn3;


#endif // FUNCTIONALITIES_H
