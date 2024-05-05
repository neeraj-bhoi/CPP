#include "Zoo.h"

Zoo::Zoo(std::string zooId) : _zooId{zooId}
{}

std::ostream &operator<<(std::ostream &os, const Zoo &rhs) {
    os << "_zooId: " << rhs._zooId;
    // AnimalPQ temp = rhs._animals;
    // while(!temp.empty()) {
    //     std::cout << temp.top();
    //     temp.pop();
    // }
    return os;
}
