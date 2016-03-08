#ifndef AUTOMATE_LUTIN_HPP
#define AUTOMATE_LUTIN_HPP

class Etat;
class Lexer;

#include <string>
#include <stack>
#include <unordered_map>
#include "Declaration.hpp"
#include "Symbole.hpp"

typedef std::unordered_map<std::string, Declaration> TableDesSymboles;


#include "Etat.hpp"
#include "valeurRetour.hpp"
#include "Lexer.hpp"
#include "Programme.hpp"
#include "Logger.hpp"

class AutomateLutin
{
public:
	AutomateLutin(const std::string& fileName, const int options);
	virtual ~AutomateLutin();
	void lecture();
	valeurRetour decalage(Symbole* symbole, Etat* etat, bool readNext);
	valeurRetour reduction(Symbole* symbole, const unsigned int nbEtats);
	Symbole* popSymbole();
	void addDeclarationToProgram(Declaration* d);
	void addInstructionToProgram(Instruction* i);
	
private:
	int options;
	std::stack<Etat*> etats;
	std::stack<Symbole*> symboles;
	TableDesSymboles tableSymboles;
	Lexer* lexer;
	Programme programme;
	
	static const Logger logger;
	
	void transformation();
	void analyseStatique();
	void execution();
	void affichage();
};

#endif // AUTOMATE_LUTIN_HPP
