#include "InstructionEcriture.hpp"

#include <iostream>
#include "StringHelper.hpp"

InstructionEcriture::InstructionEcriture(Expression* e) : Instruction(), expression(e)
{
	
}

InstructionEcriture::~InstructionEcriture()
{
	//delete expression;
}

void InstructionEcriture::print() const
{
	std::cout << "ecrire " << expression->toPrintString() << ";" << std::endl;
}

void InstructionEcriture::setExpression(Expression* e)
{
	this->expression = e;
}

void InstructionEcriture::transform(TableDesSymboles& tableDesSymboles)
{
	Expression* expressionTampon;
	expressionTampon = expression->toTransform(tableDesSymboles);
	if(expression != expressionTampon)
	{
		//delete expression;
		setExpression(expressionTampon);
	}
}

void InstructionEcriture::exec(TableDesSymboles& tableDesSymboles)
{
	double val = expression->eval(tableDesSymboles);
	std::cout << StringHelper::doubleToString(val) << std::endl;
}

std::list<std::string> InstructionEcriture::getIdentifiantsInExpression() const
{
	return expression->getIdentifiants();
}
