#pragma once
#include <stdexcept>

#include "IAccount.h"

using namespace std;

class BaseAccount : public IAccount
{
private:
    int _number;
    double _balance;
    
public:
    explicit BaseAccount(const int number)
    {
        if (number < 0)
        {
            throw invalid_argument("number is negative");
        }
        
        _number = number;
        _balance = 0;
    }
    BaseAccount(const int number, const double balance)
    {
        if (number < 0)
        {
            throw invalid_argument("number is negative");
        }

        if (balance < 0)
        {
            throw invalid_argument("balance is negative");
        }
        
        _number = number;
        _balance = balance;
    }

    int getNumber() const
    {
        return _number;
    }

    double getBalance() const
    {
        return _balance;
    }

    bool credit(const double amount) override
    {
        if (amount < 0)
        {
            throw invalid_argument("amount is negative");
        }
        
        if (amount > _balance)
        {
            return false;
        }
        
        _balance -= amount;
        return true;
        
    }

    void debit(const double amount) override
    {
        if (amount < 0)
        {
            throw invalid_argument("amount is negative");
        }
        
        _balance += amount;
    }
};
