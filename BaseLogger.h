#pragma once

#include "ILogger.h"
#include "EmptyLogger.h"

class BaseLogger : public ILogger
{
private:
	ILogger* _logger;

protected:
	explicit BaseLogger(ILogger* logger = nullptr) {
		if (logger != nullptr)
		{
			_logger = logger;
		}
		else
		{
			_logger = new EmptyLogger();
		}
	}

public:
	void log(const string& message) override {
		if (_logger == nullptr) return;

		_logger->log(message);
	}
};
