#include "InstructionAffectation.hpp"

#include <iostream>
#include "DeclarationVariable.hpp"

InstructionAffectation::InstructionAffectation(const std::string& identifiant, Expression* e)
	: Instruction(), identifiant(identifiant), expression(e)
{
	
}

InstructionAffectation::~InstructionAffectation()
{
	//delete expression;
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

void InstructionAffectation::exec(TableDesSymboles& tableDesSymboles)
{
	double val = expression->eval(tableDesSymboles);
	
	DeclarationVariable* d = (DeclarationVariable*) tableDesSymboles[identifiant];
	d->setExecValue(val);
}

std::string InstructionAffectation::getIdentifiant() const
{
	return identifiant;
}

std::list<std::string> InstructionAffectation::getIdentifiantsInExpression() const
{
	return expression->getIdentifiants();
}
