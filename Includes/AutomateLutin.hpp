#ifndef AUTOMATE_LUTIN_HPP
#define AUTOMATE_LUTIN_HPP

class Etat;
class Lexer;

#include "Declaration.hpp"
#include "Symbole.hpp"
#include "Etat.hpp"
#include "valeurRetour.hpp"
#include "Lexer.hpp"
#include "Programme.hpp"
#include "Logger.hpp"
#include "AnalyseStatique.hpp"
#include "TypeDefinitions.hpp"

#include <string>
#include <stack>
#include <set>
#include <unordered_map>

class AutomateLutin
{
public:
	AutomateLutin(const std::string& fileName, const int options);
	virtual ~AutomateLutin();
	int lecture();
	valeurRetour decalage(Symbole* symbole, Etat* etat, bool readNext);
	valeurRetour reduction(Symbole* symbole, const unsigned int nbEtats, Symbole* previousSymbol);
	Symbole* popSymbole();
	void popPoppedSymbolesSymbole(Symbole* s);
	void addDeclarationToProgram(Declaration* d);
	void addInstructionToProgram(Instruction* i);
	
private:
	int options;
	std::stack<Etat*> etats;
	std::stack<Symbole*> symboles;
	std::set<Symbole*> popedSymboles;
	std::set<Etat*> removedStates;
	TableDesSymboles tableSymboles;
	Lexer* lexer;
	Programme* programme;
	Symbole* symbolBeforeReduction;
	
	static const Logger logger;
	
	void handleUnrecognizedSymbol(Symbole* errorSymbol);
	std::string getExpectedSymbolsErrorMessage(const Etat* lastState) const;
	
	void transformation();
	void analyseStatique();
	void execution();
	void affichage();
};

#endif // AUTOMATE_LUTIN_HPP
