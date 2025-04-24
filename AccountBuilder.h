#pragma once

#include "BaseAccount.h"
#include "AccountWithPassword.h"

#include "ILogger.h"
#include "IInput.h"

enum AccountTypes
{
    BaseAccountType = 0,
    AccountWithPasswordType = 1
};

class AccountBuilder
{
private:
    int _number;
    double _balance;
    string _password;
    ILogger* _logger;
    IInput* _input;
    AccountTypes _accountType;
    
public:
    AccountBuilder()
    {
        _number = 0;
        _balance = 0.0;
        _password = "";
        _logger = nullptr;
        _input = nullptr;
        _accountType = BaseAccountType;
    }
    ~AccountBuilder()
    {
        delete _logger;
        delete _input;
    }

    AccountBuilder* setNumber(const int number)
    {
        _number = number;
        return this;
    }

    AccountBuilder* setBalance(const double balance)
    {
        _balance = balance;
        return this;
    }

    AccountBuilder* setLogger(ILogger* logger)
    {
        _logger = logger;
        return this;
    }

    AccountBuilder* setInput(IInput* input)
    {
        _input = input;
        return this;
    }

    AccountBuilder* setPassword(const string& password)
    {
        _password = password;
        _accountType = AccountWithPasswordType;
        return this;
    }

    IAccount* build()
    {
        switch (_accountType)
        {
            case AccountTypes::BaseAccountType:
            {
                return new BaseAccount(_number, _balance, _logger);
            }
            case AccountTypes::AccountWithPasswordType:
                {
                    return new AccountWithPassword(_number,_password, _balance, _input, _logger);
                }
        }
    }
};
