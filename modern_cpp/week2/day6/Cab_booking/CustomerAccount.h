
#ifndef CUSTOMERACCOUNT_H
#define CUSTOMERACCOUNT_H

#include<iostream>
#include"Gender.h"
#include"Account.h"

class CustomerAccount : public Account
{
private:
    std::string _fullname;
    Gender _customerGender;
public:
    CustomerAccount() = delete;
    CustomerAccount(const CustomerAccount&) = delete;
    CustomerAccount(const CustomerAccount&&) = delete;
    CustomerAccount& operator=(const CustomerAccount&) = delete;
    CustomerAccount& operator=(CustomerAccount&&) = delete;
    ~CustomerAccount() = default;

    CustomerAccount(std::string name, std::string fullname, Gender gGender);

    std::string fullname() const { return _fullname; }
    void setFullname(const std::string &fullname) { _fullname = fullname; }

    Gender customerGender() const { return _customerGender; }
    void setCustomerGender(const Gender &customerGender) { _customerGender = customerGender; }

    friend std::ostream &operator<<(std::ostream &os, const CustomerAccount &rhs);

    void RegisterAccount() override;
};


#endif // CUSTOMERACCOUNT_H
