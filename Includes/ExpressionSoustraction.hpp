#ifndef EXPRESSION_SOUSTRACTION_HPP
#define EXPRESSION_SOUSTRACTION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionSoustraction : public ExpressionBinaire
{
public:
	ExpressionSoustraction();
	ExpressionSoustraction( Expression* membreG , Expression* membreD );
	virtual ~ExpressionSoustraction();
	double eval(TableDesSymboles& tableDesSymboles);
	std::string toString() const;
	std::string toPrintString() const;
	Expression* toTransform();
};

#endif // EXPRESSION_SOUSTRACTION_HPP
