#ifndef FILE_LEXER_HPP
#define FILE_LEXER_HPP

#include "Lexer.hpp"
#include "Logger.hpp"
#include <vector>

class FileLexer : public Lexer
{
public:
	FileLexer(const std::string& fileName);
	virtual ~FileLexer();
	
	Symbole* getNext();

private:
	std::vector<Symbole*> symboles;
	std::vector<Symbole*>::const_iterator currentSymbole;
	
	static const Logger logger;
	
	bool isLastSymbol() const;
	void begin();
};

#endif // FILE_LEXER_HPP
