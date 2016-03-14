#ifndef INSTRUCTION_ECRITURE_HPP
#define INSTRUCTION_ECRITURE_HPP

#include "Instruction.hpp"
#include "Expression.hpp"

class InstructionEcriture : public Instruction
{
public:
	InstructionEcriture(Expression* e);
	virtual ~InstructionEcriture();
	void print() const;
	void transform();
	void exec(TableDesSymboles& tableDesSymboles);
	void setExpression(Expression* e);
private:
	Expression* expression;
};

#endif // INSTRUCTION_ECRITURE_HPP
