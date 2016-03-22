#include "LineLexer.hpp"

#include "SymbolFabric.hpp"
#include "SymboleTerminal.hpp"

LineLexer::LineLexer(const std::string& fileName) : Lexer(fileName)
{
}
	
LineLexer::~LineLexer()
{
	for (Symbole* s : currentSymbols)
		delete s;
}

Symbole* LineLexer::getNext()
{
	if (currentSymbols.size() == 0)
	{
		std::vector<Symbole*> newSymbols = getSymbolsFromNextLine();
		currentSymbols.insert(currentSymbols.begin(), newSymbols.begin(), newSymbols.end());
		
		// Still empty collection = EOF
		if (currentSymbols.size() == 0)
			return new SymboleTerminal(FIN);
	}
		
	Symbole* firstSymbol = currentSymbols.front();
	currentSymbols.pop_front();
	return firstSymbol;
}

std::vector<Symbole*> LineLexer::getSymbolsFromNextLine()
{
	std::string line = getNextLineFromFile();
	if (line == "")
		return std::vector<Symbole*>();
	
	std::vector<Symbole*> symbs;
	while ((symbs = SymbolFabric::makeSymbolsFromLine(line)).size() == 0)
	{
		line = getNextLineFromFile();
		if (line == "")
			return std::vector<Symbole*>();
	}

	return symbs;
}

std::string LineLexer::getNextLineFromFile()
{
	std::string line;
	if (getline(*fileStream, line))
		return line;

	return std::string();
}
