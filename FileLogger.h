#pragma once

#include <fstream>

#include "BaseLogger.h"

using namespace std;

class FileLogger final : public BaseLogger 
{
private:
	string _path;

	static void write(const string& message, const string& path) {
		ofstream file;
		file.open(path, ios::app);
		file << message << endl;
		file.close();
	}

public:
	explicit FileLogger(const string& path, ILogger* logger = nullptr) : BaseLogger(logger) {
		_path = path;
	}

	void log(const string& message) override {
		BaseLogger::log(message);

		FileLogger::write(message, _path);
	}
};
