#include "Logger.hpp"

#include <iostream>
#include <algorithm>

#define DEBUG
#define WARNING
//#define CONSTRUCTION_DESTRUCTION

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
	printMessage("DEBUG", msg);
#endif
}

void Logger::construction(const std::string& msg) const
{
#ifdef CONSTRUCTION_DESTRUCTION
	printMessage("CONSTRUCTION", msg);
#endif
}

void Logger::destruction(const std::string& msg) const
{
#ifdef CONSTRUCTION_DESTRUCTION
	printMessage("DESTRUCTION", msg);
#endif
}

void Logger::warning(const std::string& msg) const
{
#ifdef WARNING
	printMessage("WARNING", msg);
#endif
}

void Logger::printMessage(const std::string& msgType, const std::string& msg) const
{
	if (!isIgnored())
	{
		printClassName();
		printMessageType(msgType);
		std::cout << msg << std::endl;
	}
}

bool Logger::isIgnored() const
{
	return std::find(IGNORED_CLASSES.begin(), IGNORED_CLASSES.end(), className) != IGNORED_CLASSES.end();
}

void Logger::printClassName() const
{
	std::cout << "[" << className << "] ";
}

void Logger::printMessageType(const std::string& msgType) const
{
	std::cout << msgType << ": ";
}
