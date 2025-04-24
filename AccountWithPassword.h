#pragma once

#include <string>

#include "AccountBuilder.h"
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
    explicit AccountWithPassword(const int number, const string& password, IInput* input, ILogger* logger = nullptr)
    {
        if (password.empty())
            throw invalid_argument("password is empty");

        _password = password;
        _baseAccount = new BaseAccount(number, logger);

        _input = input;
    }

    AccountWithPassword(const int number, const string& password, const int balance, IInput* input, ILogger* logger = nullptr)
    {
        if (password.empty())
            throw invalid_argument("password is empty");

        _password = password;
        _baseAccount = new BaseAccount(number, balance, logger);

        _input = input;
    }

    ~AccountWithPassword() override
    {
        delete _baseAccount;
        delete _input;
    }

    int getNumber() const override
    {
        return _baseAccount->getNumber();
    }

    double getBalance() const override
    {
        const auto message = "enter password (for number: " + to_string(_baseAccount->getNumber()) + "): ";
        const auto password = _input->getInput(message);
        if (_password != password)
            throw invalid_argument("invalid password");
        
        return _baseAccount->getBalance();
    }

    bool credit(const double amount) override
    {
        const auto message = "enter password (for number: " + to_string(_baseAccount->getNumber()) + "): ";
        const auto password = _input->getInput(message);
        if (_password != password)
            throw invalid_argument("invalid password");

        return _baseAccount->credit(amount);
    }
    void debit(const double amount) override
    {
        const auto message = "enter password (for number: " + to_string(_baseAccount->getNumber()) + "): ";
        const auto password = _input->getInput(message);
        if (_password != password)
            throw invalid_argument("invalid password");

        _baseAccount->debit(amount);
    }
};
