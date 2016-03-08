#ifndef LINE_LEXER_HPP
#define LINE_LEXER_HPP

#include "Lexer.hpp"

class LineLexer : public Lexer
{
public:
	LineLexer(const std::string& fileName);
	virtual ~LineLexer();
	
	symbole_ptr getNext();
	symbole_ptr readNext() const;
};

#endif // LINE_LEXER_HPP
