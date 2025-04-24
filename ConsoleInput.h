#pragma once

#include <iostream>
#include <string>

#include "IInput.h"

using namespace std;

class ConsoleInput final : public IInput
{
public:
    string getInput(const string& prompt) override
    {
        cout << prompt;

        string input;
        getline(cin, input);
        return input;
    }
};
