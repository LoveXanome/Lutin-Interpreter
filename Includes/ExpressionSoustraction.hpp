#ifndef EXPRESSION_SOUSTRACTION_HPP
#define EXPRESSION_SOUSTRACTION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionSoustraction : public ExpressionBinaire
{
public:
	ExpressionSoustraction();
	ExpressionSoustraction( Expression* membreG , Expression* membreD );
	virtual ~ExpressionSoustraction();
	std::string toString() const;
	std::string toPrintString() const;
};

#endif // EXPRESSION_SOUSTRACTION_HPP
