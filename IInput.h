#pragma once

#include <string>

using namespace std;

class IInput
{
protected:
    IInput() = default;

public:
    virtual ~IInput() = default;

    virtual string getInput() = 0;
};
