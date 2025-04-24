#pragma once

#include <map>

#include "Account.h"

using namespace std;

using AccountList = map<int, BaseAccount>;

class Bank
{
private:
    AccountList _accounts;

public:
    Bank() = default;

    void add(const BaseAccount& account)
    {
        const auto number = account.getNumber();
        _accounts[number] = account;
    }

    void remove(int number)
    {
        _accounts.erase(number);
    }

    BaseAccount* find(int number)
    {
        return &_accounts[number];
    }

    static bool transfer(BaseAccount* from, BaseAccount* to, double amount)
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