#pragma once
#include <stdexcept>

#include "IAccount.h"
#include "ILogger.h"

using namespace std;

class BaseAccount : public IAccount
{
private:
    int _number;
    double _balance;

    ILogger* _logger;
    
public:
    explicit BaseAccount(const int number, ILogger* logger = nullptr)
    {
        if (number < 0)
        {
            throw invalid_argument("number is negative");
        }
        
        _number = number;
        _balance = 0;

        _logger = logger;
    }
    BaseAccount(const int number, const double balance, ILogger* logger = nullptr)
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

        _logger = logger;
    }

    int getNumber() const override
    {
        if (_logger != nullptr)
        {
            _logger->log("get number");
        }
        
        return _number;
    }

    double getBalance() const override
    {
        if (_logger != nullptr)
        {
            _logger->log("get balance");
        }
        
        return _balance;
    }

    bool credit(const double amount) override
    {
        if (amount < 0)
        {
            if (_logger != nullptr)
            {
                _logger->log("amount is negative");
            }
            throw invalid_argument("amount is negative");
        }
        
        if (amount > _balance)
        {
            if (_logger != nullptr)
            {
                _logger->log("amount > balance");
            }
            
            return false;
        }
        
        _balance -= amount;

        if (_logger != nullptr)
        {
            _logger->log("credit (" + to_string(amount) +")");
        }
        
        return true;
        
    }

    void debit(const double amount) override
    {
        if (amount < 0)
        {
            throw invalid_argument("amount is negative");
        }
        
        _balance += amount;
        if (_logger != nullptr)
        {
            _logger->log("debit (" + to_string(amount) +")");
        }
    }
};
