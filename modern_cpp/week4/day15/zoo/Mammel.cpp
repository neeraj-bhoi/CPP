#include "Mammel.h"

Mammel::Mammel(std::string name, int age, Rating rating)
    :_mammelName{name}, _mammelAge{age}, _mammelRating{rating}
{}

std::ostream &operator<<(std::ostream &os, const Mammel &rhs) {
    os << "_mammelName: " << rhs._mammelName
       << " _mammelAge: " << rhs._mammelAge
       << " _mammelRating: " << static_cast<int>(rhs._mammelRating) <<"\n";
    return os;
}

