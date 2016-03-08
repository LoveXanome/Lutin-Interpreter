#include "Logger.hpp"

#define DEBUG
#include <iostream>

Logger::Logger(const std::string& className) : className(className)
{
}

Logger::~Logger()
{
}
	
void Logger::debug(const std::string& msg) const
{
#ifdef DEBUG
	printClassName();
	std::cout << msg << std::endl;
#endif
}

void Logger::printClassName() const
{
	std::cout << "[" << className << "] ";
}
