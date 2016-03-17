#include "FileLexer.hpp"

#include "SymbolFabric.hpp"
#include "StringHelper.hpp"
#include "SymboleTerminal.hpp"

const Logger FileLexer::logger("FileLexer");

FileLexer::FileLexer(const std::string& fileName) : Lexer(fileName)
{
	// Read the whole file and create a list of all symbols
	std::string line;
	while (getline(*fileStream, line))
	{
		std::vector<Symbole*> symbs = SymbolFabric::makeSymbolsFromLine(line);
		
		for (unsigned int i = 0; i < symbs.size(); ++i)
		{
			symboles.push_back(symbs[i]);
		}
	}
	symboles.push_back(new SymboleTerminal(FIN));

	currentSymbole = symboles.begin();
}

FileLexer::~FileLexer()
{
	logger.destruction(StringHelper::format("Deleting %d symboles", symboles.size()));
	for (auto it = symboles.begin(); it != symboles.end(); ++it)
		delete (*it);
}
	
Symbole* FileLexer::getNext()
{
	if (isLastSymbol())
		return 0;
		
	Symbole* nextSymbole = *currentSymbole;
	currentSymbole++;
	logger.debug(StringHelper::format("Get next %s", nextSymbole->toString().c_str()));
	
	return nextSymbole;
}

Symbole* FileLexer::readNext() const
{
	if (isLastSymbol())
		return 0;

	return *currentSymbole;
}

bool FileLexer::isLastSymbol() const
{
	return currentSymbole == symboles.end();
}
