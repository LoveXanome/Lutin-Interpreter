#ifndef LINE_LEXER_HPP
#define LINE_LEXER_HPP

#include "Lexer.hpp"

#include <string>
#include <deque>
#include <vector>
#include "Symbole.hpp"

class LineLexer : public Lexer
{
public:
	LineLexer(const std::string& fileName);
	virtual ~LineLexer();
	
	Symbole* getNext();
	
private:
	std::deque<Symbole*> currentSymbols;
	
	std::vector<Symbole*> getSymbolsFromNextLine();
	std::string getNextLineFromFile();
};

#endif // LINE_LEXER_HPP
