
#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include <string>
#include "SymboleEnum.hpp"
#include "Symbole.hpp"
#include "Logger.hpp"

class Declaration : public Symbole
{
public:
	Declaration(const std::string& identifiant);
	Declaration(const std::string& identifiant, const SymboleEnum& enumRepresentation);
	virtual ~Declaration();
	virtual void print() const = 0;
	std::string getIdentifiant() const;

protected:
	std::string identifiant;
	static const Logger logger;
};

#endif // DECLARATION_HPP
