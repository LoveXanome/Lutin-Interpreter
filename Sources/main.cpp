#include "AutomateLutin.hpp"
#include "CommandLineParser.hpp"

#include <string>
#include <exception>

#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	try
	{
		CommandLineParser cmdLineParser(argc, argv);
		std::cout << cmdLineParser.getFileName() << std::endl;
		std::cout << cmdLineParser.getOptions() << std::endl;
		// Create AutomateLutin
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}

	// TODO command line parser + error testing + unit tests
	/*std::string fileName = argv[1];
	
	std::ifstream f(fileName);
	std::string line;
	if (! f.is_open())
		std::cerr << "File could not be opened" << std::endl;
	
	while (getline(f, line))
	{
		std::cout << line << std::endl;
	}
	f.close();*/
	
    return 0;
}
