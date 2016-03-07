#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include "Symbole.hpp"
#include "ListeDeclarations.hpp"
#include "ListeInstructions.hpp"

class Programme : public Symbole
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
