#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include <list>
#include "Instruction.hpp"
#include "Declaration.hpp"

typedef std::list<Instruction*> ListeInstructions;
typedef std::list<Declaration*> ListeDeclarations;

class Programme
{
public:
	Programme();
	virtual ~Programme();
	void addDeclaration(Declaration* d);
	void addInstruction(Instruction* i);

private:
	ListeDeclarations declarations;
	ListeInstructions instructions;
};

#endif // PROGRAMME_HPP
