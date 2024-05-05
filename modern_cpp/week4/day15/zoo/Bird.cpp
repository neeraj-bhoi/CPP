#include "Bird.h"

Bird::Bird(std::string name, int age, Rating rating)
    : _birdName{name}, _birdAge{age}, _birdRating{rating}
{}
std::ostream &operator<<(std::ostream &os, const Bird &rhs) {
    os << "_birdName: " << rhs._birdName
       << " _birdAge: " << rhs._birdAge
       << " _birdRating: " << static_cast<int>(rhs._birdRating)<<"\n";
    return os;
}
