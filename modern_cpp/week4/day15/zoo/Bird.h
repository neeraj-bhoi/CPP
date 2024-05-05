#ifndef BIRD_H
#define BIRD_H

#include<iostream>
#include<Rating.h>

class Bird
{
private:
    std::string _birdName{""};
    int _birdAge{0};
    Rating _birdRating{Rating::ZERO};

public:

    Bird() = delete;
    Bird(const Bird&) = default;
    Bird(Bird&&) = delete;
    Bird& operator=(const Bird&) = default;
    Bird& operator=(Bird&&) = delete;
    ~Bird() = default;

    Bird(std::string name, int age, Rating rating);

    std::string birdName() const { return _birdName; }
    void setBirdName(const std::string &birdName) { _birdName = birdName; }

    int birdAge() const { return _birdAge; }
    void setBirdAge(int birdAge) { _birdAge = birdAge; }

    Rating birdRating() const { return _birdRating; }
    void setBirdRating(const Rating &birdRating) { _birdRating = birdRating; }

    friend std::ostream &operator<<(std::ostream &os, const Bird &rhs);
};



#endif // BIRD_H
