#include "Lexer.hpp"

#include "StringHelper.hpp"
#include <stdexcept>

#include <iostream>

Lexer::Lexer(const std::string& fileName)
{
	fileStream = new std::ifstream(fileName);
	std::string line;
	if (!fileStream->is_open())
	{
		std::string errorMsg = StringHelper::format("File '%s' could not be opened", fileName.c_str());
		throw std::invalid_argument(errorMsg);
	}
	
	while (getline(*fileStream, line))
	{
		std::cout << line << std::endl;
	}
}

Lexer::~Lexer()
{
	fileStream->close();
	delete fileStream;
}

Symbole* Lexer::getNext()
{
	return 0;
}

Symbole* Lexer::readNext() const
{
	return 0;
}
