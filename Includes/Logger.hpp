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
	void construction(const std::string& msg) const;
	void destruction(const std::string& msg) const;
	void warning(const std::string& msg) const;

private:
	std::string className;
	
	static const std::list<std::string> IGNORED_CLASSES;
	
	void printMessage(const std::string& msgType, const std::string& msg) const;
	bool isIgnored() const;
	void printClassName() const;
	void printMessageType(const std::string& msgType) const;
};

#endif // LOGGER_HPP
