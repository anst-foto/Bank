#pragma once

#include <map>
#include <stdexcept>

#include "IAccount.h"

using namespace std;

using AccountList = map<int, IAccount*>;

class Bank
{
private:
    AccountList _accounts;

public:
    Bank() = default;

    void add(IAccount* account)
    {
        const auto number = account->getNumber();
        _accounts[number] = account;
    }

    void remove(const int number)
    {
        _accounts.erase(number);
    }

    IAccount* find(const int number)
    {
        return _accounts[number];
    }

    static bool transfer(IAccount* from, IAccount* to, const double amount)
    {
        if (amount <= 0)
        {
            throw invalid_argument("amount is invalid");
        }
        
        const auto result = from->credit(amount);
        if (!result)
        {
            return false;
        }

        to->debit(amount);
        return true;
    }
};