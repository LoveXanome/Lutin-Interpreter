#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <iostream>
#include <string>
#include "Symbole.hpp"

class ExpressionAddition : public Symbole
{
public:
	Expression();
	virtual ~Expression();
	double eval(string Variables);
	
private:
	
};

#endif // EXPRESSION_HPP