#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger
{
public:
	Logger(const std::string& className);
	~Logger();
	void debug(const std::string& msg) const;

private:
	std::string className;
	
	void printClassName() const;
};

#endif // LOGGER_HPP
