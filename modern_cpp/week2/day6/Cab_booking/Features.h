#ifndef FEATURES_H
#define FEATURES_H
#include"Account.h"
#include"AccountType.h"
#include<vector>
#include<iostream>

using AccountContainer = std::vector<Account*>;

class Features
{
private:
    /* data */
public:
    Features(/* args */) {}
    ~Features() {}

    /* Should accept reference of a container,
        an enum to decide type of account,
        then accept input, call the constructor and store pointer in AccountsContainer
    */

   static void CreateObject(AccountContainer& accounts, AccountType accountType);
};


#endif // FEATURES_H
