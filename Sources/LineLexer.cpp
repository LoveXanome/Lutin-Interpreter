#include "LineLexer.hpp"

LineLexer::LineLexer(const std::string& fileName) : Lexer(fileName)
{
	// TODO Read one line (and maybe the next)
}
	
LineLexer::~LineLexer()
{
}

Symbole* LineLexer::getNext()
{
	// TODO : read jusqu'à un espace, pv, +, -, *, /, (, ), = , :=, (...?)
	std::string nextSym;
	//*fileStream >> nextSym;
	
	//Symbole* nextSymbole = generateSymbole(nextSym);
	
	std::string line;
	while (getline(*fileStream, line))
	{
		//std::cout << line << std::endl;
	}
	
	// 
	return 0;
}

Symbole* LineLexer::readNext() const
{
	return 0;
}
