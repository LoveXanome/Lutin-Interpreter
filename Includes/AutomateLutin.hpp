#ifndef AUTOMATE_LUTIN_HPP
#define AUTOMATE_LUTIN_HPP

class Etat;

#include <string>
#include <stack>
#include "Etat.hpp"
#include "TableDesSymboles.hpp"
#include "Lexer.hpp"

class AutomateLutin
{
public:
	AutomateLutin(const std::string& fileName, const int options);
	virtual ~AutomateLutin();
	void lecture();
	void decalage(Symbole* symbole, Etat* etat);
	void reduction(Etat* etat, int nb);
	
private:
	std::stack<Etat*> etats;
	std::stack<Symbole*> symboles;
	TableDesSymboles tableSymboles;
	Lexer* lexer;
};

#endif // AUTOMATE_LUTIN_HPP
