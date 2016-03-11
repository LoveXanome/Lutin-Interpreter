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
private:
	Expression* expression;
};

#endif // INSTRUCTION_ECRITURE_HPP
