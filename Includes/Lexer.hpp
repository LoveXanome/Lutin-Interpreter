#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <fstream>
#include "Symbole.hpp"

class Lexer
{
public:
	Lexer(const std::string& fileName);
	virtual ~Lexer();
	
	virtual Symbole* getNext() = 0;
	virtual Symbole* readNext() const = 0;
	
protected:
	std::ifstream* fileStream;
};

#endif // LEXER_HPP
