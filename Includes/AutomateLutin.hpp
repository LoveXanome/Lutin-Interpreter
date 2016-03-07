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
	void reduction(Symbole* symbole);
	
private:
	int options;
	std::stack<Etat*> etats;
	std::stack<Symbole*> symboles;
	TableDesSymboles tableSymboles;
	Lexer* lexer;
	
	bool isTerminal(const Symbole* s) const;
	void transformation();
	void analyseStatique();
	void execution();
	void affichage();
};

#endif // AUTOMATE_LUTIN_HPP
