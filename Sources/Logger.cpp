#include "Logger.hpp"

#include <iostream>
#include <algorithm>

#define DEBUG

const std::list<std::string> Logger::IGNORED_CLASSES ({
	"RegexHelper",
	"SymbolFabric"
});

Logger::Logger(const std::string& className) : className(className)
{
}

Logger::~Logger()
{
}
	
void Logger::debug(const std::string& msg) const
{
#ifdef DEBUG
	if (!isIgnored())
	{
		printClassName();
		std::cout << msg << std::endl;
	}
#endif
}

void Logger::printClassName() const
{
	std::cout << "[" << className << "] ";
}

bool Logger::isIgnored() const
{
	return std::find(IGNORED_CLASSES.begin(), IGNORED_CLASSES.end(), className) != IGNORED_CLASSES.end();
}