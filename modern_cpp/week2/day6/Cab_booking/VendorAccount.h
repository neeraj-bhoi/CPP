
#ifndef VENDORACCOUNT_H
#define VENDORACCOUNT_H

#include"Account.h"
#include<iostream>
#include<vector>
#include"Driver.h"
#include"CabUnits.h"

using DriverContainer = std::vector<Driver*>;
using CabUnitsContainer = std::vector<CabUnits*>;

class VendorAccount : public Account
{
private:
    std::string _vendorName{""};
    DriverContainer _drivers {};
    CabUnitsContainer _CabUnits {};

public:
    VendorAccount() = delete;
    VendorAccount(const VendorAccount&) = delete;
    VendorAccount(const VendorAccount&&) = delete;
    VendorAccount& operator=(const VendorAccount&) = delete;
    VendorAccount& operator=(VendorAccount&&) = delete;
    ~VendorAccount() = default;

    VendorAccount(std::string username, std::string vendorname);
    VendorAccount(std::string username, std::string vendorname, const DriverContainer drivers, const CabUnitsContainer cabs);


    void RegisterAccount() override;

    friend std::ostream &operator<<(std::ostream &os, const VendorAccount &rhs);
};



#endif // VENDORACCOUNT_H
