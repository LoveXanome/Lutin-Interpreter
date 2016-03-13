#ifndef INSTRUCTION_AFFECTATION_HPP
#define INSTRUCTION_AFFECTATION_HPP

#include <string>
#include "Instruction.hpp"
#include "Expression.hpp"

class InstructionAffectation : public Instruction
{
public:
	InstructionAffectation(const std::string& identifiant, Expression* e);
	virtual ~InstructionAffectation();
	void print() const;
	 
private:
	std::string identifiant;
	Expression* expression;
};

#endif // INSTRUCTION_AFFECTATION_HPP
