#ifndef COMMAND_LINE_PARSER_HPP
#define COMMAND_LINE_PARSER_HPP

#include <string>

class CommandLineParser
{
public:
	CommandLineParser(const int argc, char** argv);
	virtual ~CommandLineParser();
	int getOptions() const;
	std::string getFileName() const;
	
private:
	/* Corresponds to the bitwise 'or' of matched options */
	int options;
	std::string fileName;

	bool isOption(const std::string arg);
	void parseOption(const std::string option);
};

#endif // COMMAND_LINE_PARSER_HPP
