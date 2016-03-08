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
	
	symbole_ptr getNext();
	symbole_ptr readNext() const;

private:
	std::vector<symbole_ptr> symboles;
	unsigned int currentIdx;
	
	static const Logger logger;
	
	bool isLastSymbol() const;
};

#endif // FILE_LEXER_HPP
