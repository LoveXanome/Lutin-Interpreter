#include "Lexer.hpp"

#include "StringHelper.hpp"
#include <stdexcept>

Lexer::Lexer(const std::string& fileName)
{
	fileStream = new std::ifstream(fileName);
	
	if (!fileStream->is_open())
	{
		std::string errorMsg = StringHelper::format("File '%s' could not be opened", fileName.c_str());
		throw std::invalid_argument(errorMsg);
	}
}

Lexer::~Lexer()
{
	fileStream->close();
	delete fileStream;
}
