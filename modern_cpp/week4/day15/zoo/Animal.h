#ifndef ANIMAL_H
#define ANIMAL_H

#include"Mammel.h"
#include"Bird.h"
#include<variant>

class Animals
{
private:
    std::variant<Mammel, Bird> _animal;
    std::string _zooId{"jungle"};

public:

    Animals() = default;
    Animals(const Animals&) = default;
    Animals(Animals&&) = default;
    Animals& operator=(const Animals&) = default;
    Animals& operator=(Animals&&) = default;
    ~Animals() = default;

    Animals(std::variant<Mammel, Bird>& animal, std::string zooId);

    friend std::ostream &operator<<(std::ostream &os, const Animals &rhs);
};



#endif // ANIMAL_H
