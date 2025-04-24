#pragma once

class Account
{
private:
    int _number;
    double _balance;
    
public:
    explicit Account(const int number)
    {
        _number = number;
        _balance = 0;
    }
    Account(const int number, const double balance)
    {
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

    bool credit(const double amount)
    {
        if (amount > _balance)
        {
            return false;
        }
        else
        {
            _balance -= amount;
            return true;
        }
    }

    void debit(const double amount)
    {
        _balance += amount;
    }
};
