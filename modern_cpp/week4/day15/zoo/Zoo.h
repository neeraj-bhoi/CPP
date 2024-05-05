#ifndef ZOO_H
#define ZOO_H

#include"Animal.h"
#include<memory>
#include<queue>

using AnimalPointer = std::shared_ptr<Animals>;

class Zoo
{
private:
    std::string _zooId{""};
    static int _animalCount;


public:

    Zoo() = default;
    Zoo(const Zoo&) = default;
    Zoo(Zoo&&) = default;
    Zoo& operator=(const Zoo&) = default;
    Zoo& operator=(Zoo&&) = default;
    ~Zoo() = default;

    Zoo(std::string zooId);

    friend std::ostream &operator<<(std::ostream &os, const Zoo &rhs);
};

#endif // ZOO_H
