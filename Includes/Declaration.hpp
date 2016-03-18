
#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include <string>
#include "Logger.hpp"

class Declaration
{
public:
	Declaration(const std::string& identifiant);
	virtual ~Declaration();
	virtual void print() const = 0;
	std::string getIdentifiant() const;
	virtual double getExecValue() const = 0;

protected:
	std::string identifiant;
	static const Logger logger;
};

#endif // DECLARATION_HPP
