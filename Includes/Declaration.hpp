
#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include <string>
#include "Symbole.hpp"

class Declaration : public Symbole
{
public:
	Declaration();
	virtual ~Declaration();

protected:
	std::string identifiant;
};

#endif // DECLARATION_HPP
