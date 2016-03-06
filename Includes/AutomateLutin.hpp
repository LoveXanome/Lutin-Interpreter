#ifndef AUTOMATE_LUTIN_HPP
#define AUTOMATE_LUTIN_HPP

class Etat;

#include <string>
#include <stack>
#include <unordered_map>
#include "Declaration.hpp"
#include "Etat.hpp"
#include "Lexer.hpp"

typedef std::unordered_map<std::string, Declaration> TableDesSymboles;

class AutomateLutin
{
public:
	AutomateLutin(const std::string& fileName, const int options);
	virtual ~AutomateLutin();
	void lecture();
	void decalage(Symbole* symbole, Etat* etat);
	void reduction(Symbole* symbole, const unsigned int nb);
	
private:
	int options;
	std::stack<Etat*> etats;
	std::stack<Symbole*> symboles;
	TableDesSymboles tableSymboles;
	Lexer* lexer;
	
	void transformation();
	void analyseStatique();
	void execution();
	void affichage();
};

#endif // AUTOMATE_LUTIN_HPP
