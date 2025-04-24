#pragma once

class IAccount
{
protected:
    IAccount() = default;
    
public:
    virtual ~IAccount() = default;
    
    virtual bool credit(double amount) = 0;
    virtual void debit(double amount) = 0;

    virtual double getBalance() const = 0;
    virtual int getNumber() const = 0;
};
