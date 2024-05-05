#include "Functionalities.h"

void Adaptor(Fntype fn, Container &data)
{
    if(data.empty()) {
        throw std::runtime_error("Data is not advailable for adaptor to do anything\n");
    }
    fn(data);
}

Fntype lfn1 = [](Container& data) { std::cout<<data.front(); };

Fntype lfn2 = [](Container& data) { std::cout<<data.back(); };

Fntype lfn3 = [](Container& data) { std::cout<<data.size(); };