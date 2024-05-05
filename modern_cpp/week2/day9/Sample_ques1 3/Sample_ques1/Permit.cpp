#include "Permit.h"
std::ostream &operator<<(std::ostream &os, const Permit &rhs)
{
    os << "_serial_number: " << rhs._serial_number
       << " _permit_duration_left: " << rhs._permit_duration_left;
    os << "Permit type: \n";

    switch (rhs._permit_type)
    {
    case PermitType::LEASE:
        os << "LEASE \n";
        break;

    case PermitType::OWNED:
        os << "OWNED \n";
        break;

    default:
        break;
    }
    return os;
}

Permit::Permit(std::string serial_number, PermitType permit_type, int permit_duration_left)
    : _serial_number{serial_number}, _permit_type{permit_type}, _permit_duration_left{permit_duration_left}
{
}