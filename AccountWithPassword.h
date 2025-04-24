#pragma once

#include <string>

#include "BaseAccount.h"
#include "IInput.h"

using namespace std;

class AccountWithPassword : public IAccount
{
private:
    BaseAccount* _baseAccount;
    string _password;

    IInput* _input;

public:
    explicit AccountWithPassword(const int number, const string& password, IInput* input)
    {
        if (password.empty())
            throw invalid_argument("password is empty");

        _password = password;
        _baseAccount = new BaseAccount(number);

        _input = input;
    }

    AccountWithPassword(const int number, const string& password, const int balance, IInput* input)
    {
        if (password.empty())
            throw invalid_argument("password is empty");

        _password = password;
        _baseAccount = new BaseAccount(number, balance);

        _input = input;
    }

    int getNumber() const
    {
        const auto password = _input->getInput();
        if (_password != password)
            throw invalid_argument("invalid password");
        
        return _baseAccount->getNumber();
    }

    double getBalance() const
    {
        const auto password = _input->getInput();
        if (_password != password)
            throw invalid_argument("invalid password");
        
        return _baseAccount->getBalance();
    }

    bool credit(double amount) override
    {
        const auto password = _input->getInput();
        if (_password != password)
            throw invalid_argument("invalid password");

        return _baseAccount->credit(amount);
    }
    void debit(double amount) override
    {
        const auto password = _input->getInput();
        if (_password != password)
            throw invalid_argument("invalid password");

        _baseAccount->debit(amount);
    }
};
