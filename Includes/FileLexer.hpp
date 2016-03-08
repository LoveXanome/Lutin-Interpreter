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
	Symbole* readNext() const;

private:
	std::vector<Symbole*> symboles;
	unsigned int currentIdx;
	
	static const Logger logger;
	
	bool isLastSymbol() const;
};

#endif // FILE_LEXER_HPP
