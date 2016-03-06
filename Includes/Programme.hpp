#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include "Symbole.hpp"
#include <list>
#include "Instruction.hpp"
#include "Declaration.hpp"

typedef std::list<Instruction> ListeInstructions;
typedef std::list<Declaration> ListeDeclarations; 

class Programme : public Symbole
{
public:
	Programme();
	virtual ~Programme();

private:
	ListeDeclarations declarations;
	ListeInstructions instructions;
};

#endif // PROGRAMME_HPP
