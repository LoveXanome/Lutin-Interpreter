#ifndef INSTRUCTION_AFFECTATION_HPP
#define INSTRUCTION_AFFECTATION_HPP

#include <string>
#include "Instruction.hpp"
#include "Expression.hpp"

class InstructionAffectation : public Instruction
{
public:
	InstructionAffectation(std::string identifiant);
	virtual ~InstructionAffectation();
	 
private:
	std::string identifiant;
	Expression expression;
};

#endif // INSTRUCTION_AFFECTATION_HPP
