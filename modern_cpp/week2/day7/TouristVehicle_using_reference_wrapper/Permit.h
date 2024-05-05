#ifndef PERMIT_H
#define PERMIT_H

#include<iostream>
#include"PermitType.h"

class Permit
{
private:
    std::string _serial_number;
    PermitType _permit_type;
    int _permit_duration_left;

    
public:
    Permit() = default;
    Permit(const Permit&) = default;
    Permit& operator=(const Permit&) = default;
    Permit(Permit&&) = default;
    Permit& operator=(Permit&&) = default;
    ~Permit() = default;

    Permit(std::string serial_number, PermitType permit_type, int permit_duration_left);

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
