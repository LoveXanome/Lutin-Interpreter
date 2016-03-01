#ifndef LEXER_HPP
#define LEXER_HPP

#include "Symbole.hpp"

class Lexer
{
public:
	Lexer();
	virtual ~Lexer();
	
	Symbole getNext();
	Symbole readNext() const;
};

#endif // LEXER_HPP
