#include "FileLexer.hpp"

#include "SymbolFabric.hpp"
#include "StringHelper.hpp"
	
const Logger FileLexer::logger("FileLexer");

FileLexer::FileLexer(const std::string& fileName) : Lexer(fileName), currentIdx(0)
{
	// Read the whole file and create a list of all symbols
	std::string line;
	while (getline(*fileStream, line))
	{
		std::vector<symbole_ptr> symbs = SymbolFabric::makeSymbolsFromLine(line);
		
		for (unsigned int i = 0; i < symbs.size(); ++i)
			symboles.push_back(symbs[i]);
	}
}

FileLexer::~FileLexer()
{
	/*for (auto it = symboles.begin(); it != symboles.end(); ++it)
		delete (*it);*/
}
	
symbole_ptr FileLexer::getNext()
{
	if (isLastSymbol())
		return 0;
		
	symbole_ptr nextSymbole = symboles[currentIdx++];
	logger.debug(StringHelper::format("Get next %s", nextSymbole->toString().c_str()));
	
	return nextSymbole;
}

symbole_ptr FileLexer::readNext() const
{
	if (isLastSymbol())
		return 0;

	return symboles[currentIdx];
}

bool FileLexer::isLastSymbol() const
{
	return currentIdx >= symboles.size();
}
