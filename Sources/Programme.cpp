#include "Programme.hpp"
#include "SymboleEnum.hpp"
#include "StringHelper.hpp"

const Logger Programme::logger("Programme");

Programme::Programme() : accepted(false)
{
	
}

Programme::~Programme()
{
	logger.destruction(StringHelper::format("Start destruction Programme (%d declaration & %d instructions )", declarations.size(), instructions.size()));

	for (Declaration* d : declarations)
		delete d;
				
	for (Instruction* i : instructions)
		delete i;
		
	Expression::deleteCreatedExpressionInOptimization();
}

void Programme::addDeclaration(Declaration* d)
{
	declarations.push_back(d);
}

void Programme::addInstruction(Instruction* i)
{
	instructions.push_back(i);
}

ListeInstructions* Programme::getInstructions()
{
	return &instructions;
}

ListeDeclarations* Programme::getDeclarations()
{
	return &declarations;
}

void Programme::print() const
{
	for (Declaration* d : declarations)
		d->print();
		
	for (Instruction* i : instructions)
		i->print();
}

void Programme::transform(TableDesSymboles& tableDesSymboles) const
{
	for (Instruction* i : instructions)
		i->transform(tableDesSymboles);
}

void Programme::exec(TableDesSymboles& tableDesSymboles) const
{
	for (Instruction* i : instructions)
		i->exec(tableDesSymboles);
}
	
bool Programme::isAccepted() const
{
	return accepted;
}

void Programme::accept()
{
	accepted = true;
}
