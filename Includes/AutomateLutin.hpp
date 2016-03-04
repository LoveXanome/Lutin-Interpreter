#ifndef AUTOMATE_LUTIN_HPP
#define AUTOMATE_LUTIN_HPP

class Etat;

#include <stack>
#include "Etat.hpp"
#include "TableDesSymboles.hpp"
#include "Lexer.hpp"

class AutomateLutin
{
public:
	AutomateLutin();
	virtual ~AutomateLutin();
	void lecture();
	
private:
	std::stack<Etat*> etats;
	std::stack<Symbole*> symboles;
	TableDesSymboles tableSymboles;
	Lexer* lexer;
};

#endif // AUTOMATE_LUTIN_HPP
