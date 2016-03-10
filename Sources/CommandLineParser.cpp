#include "CommandLineParser.hpp"

#include "LutinArgs.hpp"
#include "LutinArgsFabric.hpp"

#include <iostream>
#include <stdexcept>

CommandLineParser::CommandLineParser(const int argc, char** argv) : options(0)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		if (isOption(arg))
		{
			parseOption(arg);
		}
		else
		{
			if (fileName != "")
				throw std::invalid_argument("More than one lutin source file specified");
				
			fileName = arg;
		}
	}
	
	if (fileName == "")
		throw std::invalid_argument("Lutin source file not specified");
}

CommandLineParser::~CommandLineParser()
{
}


int CommandLineParser::getOptions() const
{
	return options;
}

std::string CommandLineParser::getFileName() const
{
	return fileName;
}

bool CommandLineParser::isOption(const std::string arg)
{
	return arg[0] == '-';
}

void CommandLineParser::parseOption(const std::string option)
{
	if (option.size() == 1)
		throw std::invalid_argument("Empty option");
	
	for (unsigned int i = 1; i < option.size(); ++i)
	{
		LutinArgs matchingOption = LutinArgsFabric::makeLutinArg(option[i]);
		options |= matchingOption;
	}
}
