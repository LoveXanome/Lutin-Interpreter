#ifndef EXPRESSION_BINAIRE_HPP
#define EXPRESSION_BINAIRE_HPP

#include "Expression.hpp"
#include "SymboleEnum.hpp"

class ExpressionBinaire : public Expression
{
public:
	ExpressionBinaire(Expression* membreG, Expression* membreD);
	virtual ~ExpressionBinaire();
	virtual double eval(TableDesSymboles& tableDesSymboles) = 0;
	virtual std::string toString() const = 0;
	virtual std::string toPrintString() const = 0;
	virtual Expression* toTransform(TableDesSymboles& tableDesSymboles) = 0;
	std::list<std::string> getIdentifiants() const;
	
protected:
	Expression* membreGauche;
	Expression* membreDroite;
};

#endif // EXPRESSION_BINAIRE_HPP
