#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <list>

class Logger
{
public:
	Logger(const std::string& className);
	~Logger();
	void debug(const std::string& msg) const;

private:
	std::string className;
	
	static const std::list<std::string> IGNORED_CLASSES;
	void printClassName() const;
	bool isIgnored() const;
};

#endif // LOGGER_HPP
