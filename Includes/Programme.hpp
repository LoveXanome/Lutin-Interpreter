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
	
	void print() const;
	void transform() const;
	bool isAccepted() const;
	void accept();

private:
	ListeDeclarations declarations;
	ListeInstructions instructions;
	bool accepted;
};

#endif // PROGRAMME_HPP
