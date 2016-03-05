#include "AutomateLutin.hpp"
#include "CommandLineParser.hpp"

#include <string>
#include <exception>
#include <iostream>

int main(int argc, char** argv)
{
	try
	{
		CommandLineParser cmdLineParser(argc, argv);
		
		std::string fileName = cmdLineParser.getFileName();
		int options = cmdLineParser.getOptions();
		
		AutomateLutin automate(fileName, options);
		automate.lecture();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	
    return 0;
}
