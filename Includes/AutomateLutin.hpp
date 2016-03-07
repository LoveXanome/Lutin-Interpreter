#ifndef AUTOMATE_LUTIN_HPP
#define AUTOMATE_LUTIN_HPP

class Etat;

#include <string>
#include <stack>
#include "Etat.hpp"
#include "TableDesSymboles.hpp"
#include "Lexer.hpp"
#include "Declaration.hpp"
#include "Programme.hpp"

class AutomateLutin
{
public:
	AutomateLutin(const std::string& fileName, const int options);
	virtual ~AutomateLutin();
	void lecture();
	void decalage(Symbole* symbole, Etat* etat, bool readNext);
	void reduction(Symbole* symbole, const unsigned int nbEtats);
	Symbole* popSymbole();
	void addDeclarationToProgram(Declaration* d);
	void addInstructionToProgram(Instruction* i);
	void 
	
private:
	int options;
	std::stack<Etat*> etats;
	std::stack<Symbole*> symboles;
	TableDesSymboles tableSymboles;
	Lexer* lexer;
	Programme programme;
	
	void transformation();
	void analyseStatique();
	void execution();
	void affichage();
};

#endif // AUTOMATE_LUTIN_HPP
