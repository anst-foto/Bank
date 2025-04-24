#pragma once

#include <map>

#include "Account.h"

using namespace std;

using AccountList = map<int, Account>;

class Bank
{
private:
    AccountList _accounts;

public:
    Bank() {}

    void add(Account& account)
    {
        auto number = account.getNumber();
        _accounts[number] = account;
    }

    void remove(int number)
    {
        _accounts.erase(number);
    }

    Account* find(int number)
    {
        return &_accounts[number];
    }

    static bool transfer(Account* from, Account* to, double amount)
    {
        const auto result = from->credit(amount);
        if (!result)
        {
            return false;
        }

        to->debit(amount);
        return true;
    }
};