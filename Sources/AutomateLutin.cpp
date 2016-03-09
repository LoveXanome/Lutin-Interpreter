#include "AutomateLutin.hpp"

#include "StringHelper.hpp"
#include "FileLexer.hpp"
#include "Programme.hpp"
#include "E0.hpp"
#include "LutinArgs.hpp"
#include "Identifiant.hpp"
#include "Valeur.hpp"
#include "SymboleTerminal.hpp"
#include <set>
#include <iostream>
#include "SymbolFabric.hpp"

const Logger AutomateLutin::logger("AutomateLutin");

AutomateLutin::AutomateLutin(const std::string& fileName, const int options) : options(options), symbolBeforeReduction(0)
{
	lexer = new FileLexer(fileName);
	
	etats.push(new E0);
}

AutomateLutin::~AutomateLutin()
{
	int nbSymboles = symboles.size();
	
	std::set<Symbole*> uniqueSymboles;
	while (!symboles.empty())
	{
		Symbole* s = symboles.top();
		symboles.pop();
		uniqueSymboles.insert(s);
	}
	
	logger.debug(StringHelper::format("Start destruction (%d etats & %d symboles (unique %d))", etats.size(), nbSymboles, uniqueSymboles.size()));


	while (!etats.empty())
	{
		Etat* e = etats.top();
		etats.pop();
		delete e;
	}
	
	/*for (Symbole* s : uniqueSymboles)
		delete s;*/
	
	delete lexer;
	logger.debug("End destruction");
}

void AutomateLutin::lecture()
{
	logger.debug("Debut lecture");
	
	Symbole* firstSymbole = lexer->getNext();
	valeurRetour retour = etats.top()->transition(this, firstSymbole);
	
	if (retour == NON_RECONNU)
		logger.debug("Non reconnu");
	
	if (options & TRANSFORMATION)
		transformation();
	
	if (options & ANALYSE_STATIQUE)
		analyseStatique();
	
	if (options & EXECUTION)
		execution();
	
	if (options & AFFICHAGE)
		affichage();
		
	logger.debug(StringHelper::format("Fin lecture (valeur retour : %d)", retour));
}

valeurRetour AutomateLutin::decalage(Symbole* symbole, Etat* etat, bool readNext)
{	
	logger.debug(StringHelper::format("Decalage vers etat %s (symbole %s) (read next : %d)", etat->toString().c_str(), symbole->toString().c_str(), readNext));
	
	symboles.push(symbole);
	if (symbolBeforeReduction != 0)
	{
		symbole = symbolBeforeReduction;
		symboles.push(symbole);
		symbolBeforeReduction = 0;
	}
	etats.push(etat);
	
	if (readNext)
		symbole = lexer->getNext();
	
	valeurRetour ret = etat->transition(this, symbole);
	
	if (ret == NON_RECONNU)
	{
		std::cerr << "Unexpected symbol " << symbole->toString() << " Expected : ";
		/*std::vector<SymboleEnum> expectedEnum = etat->getExpectedSymbols();
		for (SymboleEnum currentEnum : expectedEnum)
			std::cerr << SymbolFabric::makeSymbolNameFromNumber(currentEnum) << ", ";*/
		std::cerr << std::endl;
	}
	
	return ret;
}

valeurRetour AutomateLutin::reduction(Symbole* symbole, const unsigned int nbEtats, Symbole* previousSymbol)
{
	for (unsigned int i = 0; i < nbEtats; ++i)
		etats.pop();
	
	logger.debug(StringHelper::format("Reduction de %d etats. Appel de %s (symbole %s)", nbEtats, etats.top()->toString().c_str(), symbole->toString().c_str()));
	
	symbolBeforeReduction = previousSymbol;
	
	Etat* etat = etats.top();
	valeurRetour ret = etat->transition(this, symbole);
	
	if (ret == NON_RECONNU)
	{
		std::cerr << "Unexpected symbol " << symbole->toString() << " Expected : ";
		/*std::vector<SymboleEnum> expectedEnum = etat->getExpectedSymbols();
		for (SymboleEnum currentEnum : expectedEnum)
			std::cerr << SymbolFabric::makeSymbolNameFromNumber(currentEnum) << ", ";*/
		std::cerr << std::endl;
	}
	
	return ret;
}

Symbole* AutomateLutin::popSymbole()
{
	Symbole* s = symboles.top();
	symboles.pop();
	return s;
}

void AutomateLutin::addDeclarationToProgram(Declaration* d)
{
	programme.addDeclaration(d);
}

void AutomateLutin::addInstructionToProgram(Instruction* i)
{
	programme.addInstruction(i);
}

void AutomateLutin::transformation()
{
	// TODO (version plus tard)
}

void AutomateLutin::analyseStatique()
{
	// TODO (version plus tard)
}

void AutomateLutin::execution()
{
	// TODO (version plus tard)
}

void AutomateLutin::affichage()
{
	// TODO (version plus tard)
}
