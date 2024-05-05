#include "CustomerAccount.h"

std::ostream &operator<<(std::ostream &os, const CustomerAccount &rhs) {
    os << "_fullname: " << rhs._fullname;
    std::string val;
    if(rhs._customerGender == Gender::MALE) {
        val = "MALE";
    } else if(rhs._customerGender == Gender::FEMALE) {
        val = "FEMALE";
    } else {
        val = "OTHERS";
    }
    os<< " _customerGender: " << val;
    return os;
}

// Customer::Customer(std::string name, Gender gGender_customerGender) 
//     :_fullname{name}, _customerGender{gGender_customerGender}
// {
// }

CustomerAccount::CustomerAccount(std::string name, std::string fullname, Gender gtype)
    :Account(name), _fullname{fullname}, _customerGender{gtype}
{
}

void CustomerAccount::RegisterAccount()
{
    std::cout<<"Account verified via otp\n";
    // _flag = true;    //account is verified (yes/no)
}
