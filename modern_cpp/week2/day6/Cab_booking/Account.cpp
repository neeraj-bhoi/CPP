#include "Account.h"

unsigned long Account::_counter = 90000;

Account::Account(std::string name) 
    : _username{name}, _userid{++_counter}
{}

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "_username: " << rhs._username
       << " _userid: " << rhs._userid;
    return os;
}
