#ifndef AUTOMATE_LUTIN_HPP
#define AUTOMATE_LUTIN_HPP

#include <stack>
#include "Etat.hpp"

class AutomateLutin
{
public:
	AutomateLutin();
	virtual ~AutomateLutin();
	void lecture();
	
private:
	std::stack<Etat> etats;
	std::stack<Etat> symboles;
};

#endif // AUTOMATE_LUTIN_HPP
