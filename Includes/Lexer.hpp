#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <fstream>
#include "Symbole.hpp"
#include "AutomateLutin.hpp"

class Lexer
{
public:
	Lexer(const std::string& fileName);
	virtual ~Lexer();
	
	virtual symbole_ptr getNext() = 0;
	virtual symbole_ptr readNext() const = 0;
	
protected:
	std::ifstream* fileStream;
};

#endif // LEXER_HPP
