#include "AutomateLutin.hpp"

#include "StringHelper.hpp"
#include "FileLexer.hpp"
#include "LineLexer.hpp"
#include "Programme.hpp"
#include "E0.hpp"
#include "LutinArgs.hpp"
#include "Identifiant.hpp"
#include "Valeur.hpp"
#include "SymboleTerminal.hpp"
#include "SymbolFabric.hpp"
#include "SymboleDefaut.hpp"

#include <set>
#include <iostream>
#include <string>
#include <stdexcept>

const Logger AutomateLutin::logger("AutomateLutin");

AutomateLutin::AutomateLutin(const std::string& fileName, const int options) : options(options), symbolBeforeReduction(0)
{
	//lexer = new FileLexer(fileName);
	lexer = new LineLexer(fileName);
	
	etats.push(new E0);

	programme = new Programme();
}

AutomateLutin::~AutomateLutin()
{		
	logger.destruction("Start destruction AutomateLutin");
		
	logger.destruction(StringHelper::format("========== Destruction des états (%d) ==========", etats.size()));
	while (!etats.empty())
	{
		Etat* e = etats.top();
		etats.pop();
		delete e;
	}
	
	logger.destruction("========== Popped symbols ========== ");
	for (Symbole* s : popedSymboles)
		delete s;
			
	logger.destruction("========== Removed states ========== ");
	for (Etat* e : removedStates)
		delete e;
	
	logger.destruction(StringHelper::format("========== Deleting %d symbols ========== ", symboles.size()));
	std::set<Symbole*> uniqueSymbols;
	while (!symboles.empty())
	{
		Symbole* s = symboles.top();
		symboles.pop();
		uniqueSymbols.insert(s);
	}
	for (Symbole* s : uniqueSymbols)
		delete s;
	
	delete programme;
	delete lexer;

	logger.destruction("End destruction");
}

int AutomateLutin::lecture()
{
	logger.debug("Debut lecture");
	
	Symbole* firstSymbole = lexer->getNext();

	etats.top()->transition(this, firstSymbole);
	
	if (!programme->isAccepted())
	{
		std::cerr << "Programme invalide" << std::endl;
		return 1;
	}
	
	if (options & ANALYSE_STATIQUE || options & TRANSFORMATION || options & EXECUTION)
		analyseStatique();
	
	if (options & TRANSFORMATION)
		transformation();
	
	if (options & AFFICHAGE)
		affichage();
	
	if (options & EXECUTION)
		execution();
	
		
	logger.debug("Fin lecture");
	return 0;
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
	
	if (ret == ACCEPTE)
	{
		//Ajoute le symbole FIN dans la pile pour qu'il soit supprimé dans le desctructeur
		symboles.push(symbole);

		programme->accept();
		logger.debug("Programme accepté !");
	}

	// Si on a une erreur, on va essayer de lire le symbole suivant, et si on à une encore une erreur => stop
	if (ret == NON_RECONNU)
	{
		handleUnrecognizedSymbol(symbole);
		delete symbole;
	}	
	
	return ret;
}

void AutomateLutin::handleUnrecognizedSymbol(Symbole* errorSymbol)
{
	Etat* dernierEtat = etats.top();
	Symbole* nextSymbol = lexer->getNext();
	valeurRetour ret2;

	if (nextSymbol != 0) // if not end of file
	{
		logger.debug(StringHelper::format("Unexpected symbol, try again : state %s with symbol %s", dernierEtat->toString().c_str(), nextSymbol->toString().c_str()));
		ret2 = dernierEtat->transition(this, nextSymbol);
		// Si le nouveau symbole est à nouveau pas reconnu
		if (ret2 == NON_RECONNU)
		{
			std::string errorMsg = StringHelper::format("Unexpected symbols %s (and then %s). Expected: %s",
															errorSymbol->toString().c_str(),
															nextSymbol->toString().c_str(),
															getExpectedSymbolsErrorMessage(dernierEtat).c_str());
			delete errorSymbol;
			delete nextSymbol;
			throw std::runtime_error(errorMsg);
		}
		else if (dernierEtat->toString() != Etat::ACCEPT_STATE) // Only show warning if not last state
			logger.debug(StringHelper::format("Warning: Encountered an unexpected symbol %s and expecting: %s , but could continue", errorSymbol->toString().c_str(), getExpectedSymbolsErrorMessage(dernierEtat).c_str()));
	}
	else if (dernierEtat->toString() != Etat::ACCEPT_STATE)
	{
		std::string errorMsg = StringHelper::format("Unexpected end of file (%s). Expected: %s", symboles.top()->toString().c_str(), getExpectedSymbolsErrorMessage(dernierEtat).c_str());
		delete errorSymbol;
		throw std::runtime_error(errorMsg);
	}
}

std::string AutomateLutin::getExpectedSymbolsErrorMessage(const Etat* lastState) const
{
	std::vector<SymboleEnum> expectedEnum = lastState->getExpectedSymbols();
	std::string errorMessage;

	bool onePassageAtLeast = false;
	for (SymboleEnum currentEnum : expectedEnum)
	{
		errorMessage.append(SymbolFabric::makeSymbolNameFromNumber(currentEnum));
		errorMessage.append(", ");
		onePassageAtLeast = true;
	}

	// Supprime la derniere virgule
	if (onePassageAtLeast)
		errorMessage.resize(errorMessage.size() - 2);
	
	return errorMessage;
}

valeurRetour AutomateLutin::reduction(Symbole* symbole, const unsigned int nbEtats, Symbole* previousSymbol)
{

	for (unsigned int i = 0; i < nbEtats; ++i)
	{
		Etat* e = etats.top();
		etats.pop();
		removedStates.insert(e);
	}
	
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
	logger.debug(StringHelper::format("POP symbol : %s", s->toString().c_str()));
	popedSymboles.insert(s);
	return s;
}

void AutomateLutin::popPoppedSymbolesSymbole(Symbole* s)
{
	popedSymboles.erase(popedSymboles.find(s));
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
	programme->transform(tableSymboles);
}

void AutomateLutin::analyseStatique()
{
	AnalyseStatique analyseStatique(&tableSymboles, programme);
	analyseStatique.check();
}

void AutomateLutin::execution()
{
	programme->exec(tableSymboles);
}

void AutomateLutin::affichage()
{
	programme->print();
}
