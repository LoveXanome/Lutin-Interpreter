#ifndef INSTRUCTION_ECRITURE_HPP
#define INSTRUCTION_ECRITURE_HPP

class Expression;

#include "Instruction.hpp"
#include "Expression.hpp"

class InstructionEcriture : public Instruction
{
public:
	InstructionEcriture(Expression* e);
	virtual ~InstructionEcriture();
	void print() const;
	void transform(TableDesSymboles& tableDesSymboles);
	void exec(TableDesSymboles& tableDesSymboles);
	void setExpression(Expression* e);
	std::list<std::string> getIdentifiantsInExpression() const;
	
private:
	Expression* expression;
};

#endif // INSTRUCTION_ECRITURE_HPP
