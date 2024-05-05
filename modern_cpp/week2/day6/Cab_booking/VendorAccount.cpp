#include "VendorAccount.h"

VendorAccount::VendorAccount(std::string username, std::string vendorname)
    :Account(username), _vendorName{vendorname}
{

}

VendorAccount::VendorAccount(std::string username, std::string vendorname, const DriverContainer drivers, const CabUnitsContainer cabs)
    :VendorAccount(username, vendorname)
{
    _drivers = drivers;
    _CabUnits = cabs;
}


std::ostream &operator<<(std::ostream &os, const VendorAccount &rhs) {
    os << static_cast<const Account &>(rhs)
       << " _vendorName: " << rhs._vendorName;
    return os;
}

void VendorAccount::RegisterAccount()
{
    std::cout<<"Vendor verified as per govt norms\n";
}
