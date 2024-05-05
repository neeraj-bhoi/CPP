/*
    _id
    _username
    _static counter

    disable all special destructor
    << operator
    RegisterAccount() = 0;
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>

class Account
{
private:
    static unsigned long _counter;
    std::string _username;
    unsigned long _userid;
public:
    Account() = delete;
    Account(const Account&) = delete;
    Account(const Account&&) = delete;
    Account& operator=(const Account&) = delete;
    Account& operator=(Account&&) = delete;
    ~Account() = default;
    explicit Account(std::string name);  //explicit:

    virtual void RegisterAccount() = 0;

    std::string username() const { return _username; }
    void setUsername(const std::string &username) { _username = username; }

    unsigned long userid() const { return _userid; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs); 
    
};

#endif // ACCOUNT_H
