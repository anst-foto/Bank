#pragma once

#include "ILogger.h"

class EmptyLogger final : public ILogger
{
public:
	void log(const string& message) override {} //FIXME
};
