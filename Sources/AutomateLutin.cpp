#include "AutomateLutin.hpp"

#include "StringHelper.hpp"
#include "FileLexer.hpp"
#include "Programme.hpp"
#include "E0.hpp"
#include "LutinArgs.hpp"
#include "Identifiant.hpp"
#include "Valeur.hpp"
#include "SymboleTerminal.hpp"
#include "SymbolFabric.hpp"

#include <set>
#include <iostream>
#include <string>
#include <stdexcept>

const Logger AutomateLutin::logger("AutomateLutin");

AutomateLutin::AutomateLutin(const std::string& fileName, const int options) : options(options), symbolBeforeReduction(0)
{
	lexer = new FileLexer(fileName);
	
	etats.push(new E0);

	programme = new Programme();
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
	
	logger.destruction(StringHelper::format("Start destruction (%d etats & %d symboles (unique %d))", etats.size(), nbSymboles, uniqueSymboles.size()));


	while (!etats.empty())
	{
		Etat* e = etats.top();
		etats.pop();
		delete e;
	}
	
	/*for (Symbole* s : uniqueSymboles)
		delete s;*/
	
	delete programme;
	
	delete lexer;
	logger.destruction("End destruction");
}

void AutomateLutin::lecture()
{
	logger.debug("Debut lecture");
	
	Symbole* firstSymbole = lexer->getNext();

	valeurRetour retour = etats.top()->transition(this, firstSymbole);
	
	if (retour == NON_RECONNU)
		logger.debug("Non reconnu, lue : " + firstSymbole->toString());
	
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
	logger.debug(StringHelper::format("Decalage vers etat %s (stacked symbole %s) (read next : %d)", etat->toString().c_str(), symbole->toString().c_str(), readNext));
	
	symboles.push(symbole);
	
	// Si on vient de faire une réduction, on récupère le symbole qu'on avait avant
	if (symbolBeforeReduction != 0)
	{
		symbole = symbolBeforeReduction;
		logger.debug(StringHelper::format("Coming from reduction : %s", symbole->toString().c_str()));
		symbolBeforeReduction = 0;
	}
	else if (readNext) // Si la transition provient d'un symbole terminal, on lit le suivant du fichier
		symbole = lexer->getNext();
	
	etats.push(etat);
	
	// Récupère la valeur de retour de la transition
	valeurRetour ret = etat->transition(this, symbole);
	
	// Si on a une erreur, on va essayer de lire le symbole suivant, et si on à une encore une erreur => stop
	if (ret == NON_RECONNU)
		handleUnrecognizedSymbol(symbole);
	
	return ret;
}

void AutomateLutin::handleUnrecognizedSymbol(Symbole* errorSymbol)
{
	Symbole* nextSymbol = lexer->getNext();
	valeurRetour ret2;
	
	if (nextSymbol != 0) // if not end of file
	{
		ret2 = etats.top()->transition(this, nextSymbol);
		
		std::vector<SymboleEnum> expectedEnum = etats.top()->getExpectedSymbols();
		std::string errorMessage;
		
		for (SymboleEnum currentEnum : expectedEnum)
		{
			errorMessage.append(SymbolFabric::makeSymbolNameFromNumber(currentEnum));
			errorMessage.append(", ");
		}
		// Supprime la derniere virgule
		errorMessage.resize(errorMessage.size() - 2);
		
		// Si le nouveau symbole est à nouveaux pas reconnu
		if (ret2 == NON_RECONNU)
			throw std::runtime_error(StringHelper::format("Unexpected symbols %s (and then %s). Expected: %s", errorSymbol->toString().c_str(), nextSymbol->toString().c_str(), errorMessage.c_str()));
		else
			std::cerr << "Warning: Encountered an unexpected symbol " << errorSymbol->toString() << " and expecting: " << errorMessage << " but could continue" << std::endl;
	}
}

valeurRetour AutomateLutin::reduction(Symbole* symbole, const unsigned int nbEtats, Symbole* previousSymbol)
{
	for (unsigned int i = 0; i < nbEtats; ++i)
		etats.pop();
	
	logger.debug(StringHelper::format("Reduction de %d etats. Retour vers %s (symbole %s)", nbEtats, etats.top()->toString().c_str(), symbole->toString().c_str()));
	
	symbolBeforeReduction = previousSymbol;
	
	Etat* etat = etats.top();
	valeurRetour ret = etat->transition(this, symbole);
	
	if (ret == NON_RECONNU)
	{
		std::cerr << "Unexpected symbol " << symbole->toString() << " Expected : ";
		std::vector<SymboleEnum> expectedEnum = etat->getExpectedSymbols();
		for (SymboleEnum currentEnum : expectedEnum)
			std::cerr << SymbolFabric::makeSymbolNameFromNumber(currentEnum) << ", ";
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

void AutomateLutin::addSymbole(Symbole* symbole)
{
	symboles.push(symbole);
}

void AutomateLutin::addDeclarationToProgram(Declaration* d)
{
	programme->addDeclaration(d);
}

void AutomateLutin::addInstructionToProgram(Instruction* i)
{
	programme->addInstruction(i);
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
	programme->print();
}
