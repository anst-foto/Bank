#pragma once

#include <iostream>

#include "BaseLogger.h"

using namespace std;

class ConsoleLogger final : public BaseLogger
{
public:
	explicit ConsoleLogger(ILogger* logger = nullptr) : BaseLogger(logger) { }

	void log(const string& message) override {
		BaseLogger::log(message);

		cout << message << endl;
	}
};
