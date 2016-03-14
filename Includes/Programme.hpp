#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include <list>
#include "Instruction.hpp"
#include "Declaration.hpp"
#include "Logger.hpp"

typedef std::list<Instruction*> ListeInstructions;
typedef std::list<Declaration*> ListeDeclarations;

class Programme
{
public:
	Programme();
	virtual ~Programme();
	void addDeclaration(Declaration* d);
	void addInstruction(Instruction* i);

	ListeInstructions* getInstructions();
	ListeDeclarations* getDeclarations();
	
	void print() const;
	bool isAccepted() const;
	void accept();

private:
	ListeDeclarations declarations;
	ListeInstructions instructions;
	bool accepted;
	static const Logger logger;
};

#endif // PROGRAMME_HPP
