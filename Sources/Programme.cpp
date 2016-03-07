#include "Programme.hpp"

#include "SymboleEnum.hpp"

Programme::Programme() : Symbole(E)
{
	
}

Programme::~Programme()
{
	
}

void Programme::addDeclaration(Declaration* d)
{
	declarations.push_back(d);
}

void Programme::addInstruction(Instruction* i)
{
	instructions.push_back(i);
}
