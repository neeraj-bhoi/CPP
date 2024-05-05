#include "Animal.h"

Animals::Animals(std::variant<Mammel, Bird>& animal, std::string zooId)
    : _animal{animal}, _zooId{zooId}
{}

std::ostream &operator<<(std::ostream &os, const Animals &rhs) {
    os << " _zooId: " << rhs._zooId;
    if(std::holds_alternative<Bird> (rhs._animal)) {
        Bird ow = std::get<1> (rhs._animal);
        os<< ow;
    } else if(std::holds_alternative<Mammel> (rhs._animal)) {
        Mammel ow = std::get<0> (rhs._animal);
        os<< ow;
    }
    os << "\n";
    return os;
}
