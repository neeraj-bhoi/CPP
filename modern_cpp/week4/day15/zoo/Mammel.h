#ifndef MAMMEL_H
#define MAMMEL_H

#include<iostream>
#include<Rating.h>

class Mammel
{
private:
    std::string _mammelName {""};
    int _mammelAge {0};
    Rating _mammelRating {Rating::ZERO};

public:
    Mammel() = delete;
    Mammel(const Mammel&) = default;
    Mammel(Mammel&&) = delete;
    Mammel& operator=(const Mammel&) = default;
    Mammel& operator=(Mammel&&) = delete;
    ~Mammel() = default;

    Mammel(std::string name, int age, Rating rating);

    friend std::ostream &operator<<(std::ostream &os, const Mammel &rhs);
};



#endif // MAMMEL_H

