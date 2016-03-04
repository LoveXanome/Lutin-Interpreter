#include "CommandLineParser.hpp"

#include "LutinArgs.hpp"
#include "LutinArgsFabric.hpp"

#include <iostream>

CommandLineParser::CommandLineParser(const int argc, char** argv) : options(0)
{
	for (int i = 0; i < argc; ++i)
	{
		std::string arg(argv[i]);
		if (isOption(arg))
		{
			parseOption(arg); // TODO may throw error if option is not allowed (error code or exception?)
		}
		else
		{
			// TODO If defined twice : error
			// TODO If not specified (at the end of loop) : error
			fileName = arg;
		}
	}
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
	for (unsigned int i = 1; i < option.size(); ++i)
	{
		LutinArgs matchingOption = LutinArgsFabric::makeLutinArg(option[i]);
		options |= matchingOption;
	}
}
