#include "ListeInstructions.hpp"

ListeInstructions::ListeInstructions(string identifiant):identifiant(identifiant)
{
	
}

ListeInstructions::~ListeInstructions()
{
	
}
 
void ListeInstructions::addInstruction(Instruction instruction)
{
	this->vInstructions.push_back(instruction);
}

vector<Instruction>::iterator ListeInstructions::getIterator()
{
	return this->vInstructions.begin();
}
