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
	
	Symbole* getNext();
	Symbole* readNext() const;
	
private:
	std::ifstream* fileStream;
};

#endif // LEXER_HPP
