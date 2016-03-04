#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "Symbole.hpp"

class Lexer
{
public:
	Lexer(std::string fileName);
	virtual ~Lexer();
	
	Symbole* getNext();
	Symbole* readNext() const;
	
private:
	
};

#endif // LEXER_HPP
