#ifndef LISTE_DECLARATIONS_HPP
#define LISTE_DECLARATIONS_HPP

#include <vector>
#include "Declaration.hpp"

class ListeDeclarations : public std::vector<Declaration>
{
public:
	ListeDeclarations();
	virtual ~ListeDeclarations();
};

#endif // LISTE_DECLARATION_HPP
