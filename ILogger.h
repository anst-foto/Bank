#pragma once

#include <string>

using namespace std;

class ILogger
{
protected:
	ILogger() = default;
	
public:
	virtual ~ILogger() = default;
	
	virtual void log(const string& message) = 0;
};
