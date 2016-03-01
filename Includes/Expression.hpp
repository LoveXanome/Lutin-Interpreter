#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>
#include "Symbole.hpp"

class Expression : public Symbole
{
public:
	Expression();
	virtual ~Expression();
	double eval(std::string variables);
};

#endif // EXPRESSION_HPP
