#include "InstructionAffectation.hpp"
#include <iostream>

InstructionAffectation::InstructionAffectation(const std::string& identifiant, Expression* e)
	: Instruction(), identifiant(identifiant), expression(e)
{
	
}

InstructionAffectation::~InstructionAffectation()
{
	delete expression;
}

void InstructionAffectation::print() const
{
	std::cout << identifiant << " := " << expression->toPrintString() << ";" << std::endl;
}

void InstructionAffectation::setExpression(Expression* e)
{
	this->expression = e;
}

void InstructionAffectation::transform()
{
	Expression* expressionTampon;
	expressionTampon = expression->toTransform();
	if(expression != expressionTampon)
	{
		//delete expression;
		setExpression(expressionTampon);
	}
}
