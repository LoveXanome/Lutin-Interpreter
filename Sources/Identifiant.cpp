#include "Identifiant.hpp"
#include "DeclarationConstante.hpp"
#include "SymbolFabric.hpp"
#include "DeclarationVariable.hpp"
#include "Valeur.hpp"

Identifiant::Identifiant(const std::string& identifiant) : Identifiant(identifiant, IDENTIFIANT)
{
}


Identifiant::Identifiant(const std::string& identifiant, const SymboleEnum& enumRepresentation) : Expression(enumRepresentation), identifiant(identifiant)
{
}


Identifiant::~Identifiant()
{
}

std::string Identifiant::getIdentifiant() const
{
	return identifiant;
}

std::string Identifiant::toString() const
{
	return identifiant + "(" + SymbolFabric::makeSymbolNameFromNumber(enumRepresentation) + ")";
}

std::string Identifiant::toPrintString() const
{
	return identifiant;
}

Expression* Identifiant::toTransform(TableDesSymboles& tableDesSymboles)
{
	Declaration* d = tableDesSymboles[identifiant];
	
	if(d != NULL)
	{
		if(DeclarationConstante* constante = dynamic_cast<DeclarationConstante*>(d))
		{	
			return new Valeur(constante->getExecValue());
		}
	}
	return this;
}

double Identifiant::eval(TableDesSymboles& tableDesSymboles)
{
	Declaration* d = tableDesSymboles[identifiant];
	return d->getExecValue();
}

std::list<std::string> Identifiant::getIdentifiants() const
{
	return std::list<std::string>({identifiant});
}
