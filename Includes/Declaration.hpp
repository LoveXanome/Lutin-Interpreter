#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include <string>

class Declaration
{
public:
	Declaration();
	virtual ~Declaration();

protected:
	std::string identifiant;
};

#endif // DECLARATION_HPP