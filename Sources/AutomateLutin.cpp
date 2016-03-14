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
#include "SymboleDefaut.hpp"

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
	logger.destruction(StringHelper::format("Start destruction AutomateLutin (%d etats )", etats.size()));
	
	//Crée une liste unique de symboles
	std::vector<Symbole*> symbolesToBeDeleted;
	while (!symboles.empty())
	{
		Symbole* s = symboles.top();
		symboles.pop();
		//Ajout dans la liste des symboles à supprimer si il est pas déjà dans la liste des symboles lus par le lexer 
		//(symboles généré au cours de la création des états)
		if(! ((FileLexer*)lexer)->isInList(s) )
			symbolesToBeDeleted.push_back(s);
	}

	logger.destruction("========== Destruction des symboles  ==========");
	for (Symbole* s : symbolesToBeDeleted)
	{
		delete s;
	}	
	
	
	logger.destruction("========== Destruction des états ==========");
	while (!etats.empty())
	{
		Etat* e = etats.top();
		etats.pop();
		delete e;
	}
	
	
	//Destruction des symboles créer lors des réducions
	//On ôte de la liste le 'E' généré pour la dernière réduction
	reductionSymboles.pop();
	logger.destruction(StringHelper::format("========== Destruction des symboles générées (%d)==========", reductionSymboles.size()));
	while (!reductionSymboles.empty())
	{
		Symbole* s = reductionSymboles.top();
		reductionSymboles.pop();
		if(dynamic_cast<SymboleDefaut*>(s) != NULL)
			delete s;
	} 

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
	
	// TODO Faire analyse statique si exec ou optimisation
	if (options & TRANSFORMATION)
		transformation();
	
	if (options & ANALYSE_STATIQUE)
		analyseStatique();
	
	if (options & EXECUTION)
		execution();
	
	if (options & AFFICHAGE)
		affichage();
		
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
		programme->accept();
		logger.debug("Programme accepté !");
	}
	
	// Si on a une erreur, on va essayer de lire le symbole suivant, et si on à une encore une erreur => stop
	if (ret == NON_RECONNU)
		handleUnrecognizedSymbol(symbole);
	
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
			throw std::runtime_error(StringHelper::format("Unexpected symbols %s (and then %s). Expected: %s",
															errorSymbol->toString().c_str(),
															nextSymbol->toString().c_str(),
															getExpectedSymbolsErrorMessage(dernierEtat).c_str()));
		else if (dernierEtat->toString() != Etat::ACCEPT_STATE) // Only show warning if not last state
				std::cerr << "Warning: Encountered an unexpected symbol " << errorSymbol->toString() << " and expecting: " << getExpectedSymbolsErrorMessage(dernierEtat) << ", but could continue" << std::endl;
	}
	else if (dernierEtat->toString() != Etat::ACCEPT_STATE)
		throw std::runtime_error(StringHelper::format("Unexpected end of file (%s). Expected: %s", symboles.top()->toString().c_str(), getExpectedSymbolsErrorMessage(dernierEtat).c_str()));
}

std::string AutomateLutin::getExpectedSymbolsErrorMessage(const Etat* lastState) const
{
	std::vector<SymboleEnum> expectedEnum = lastState->getExpectedSymbols();
	std::string errorMessage;
		
	for (SymboleEnum currentEnum : expectedEnum)
	{
		errorMessage.append(SymbolFabric::makeSymbolNameFromNumber(currentEnum));
		errorMessage.append(", ");
	}
	// Supprime la derniere virgule
	errorMessage.resize(errorMessage.size() - 2);
	
	return errorMessage;
}

valeurRetour AutomateLutin::reduction(Symbole* symbole, const unsigned int nbEtats, Symbole* previousSymbol)
{
	for (unsigned int i = 0; i < nbEtats; ++i)
	{
		Etat* e = etats.top();
		etats.pop();
		delete e;
	}	
	
	logger.debug(StringHelper::format("Reduction de %d etats. Retour vers %s (symbole %s)", nbEtats, etats.top()->toString().c_str(), symbole->toString().c_str()));
	
	symbolBeforeReduction = previousSymbol;
	reductionSymboles.push(symbole);
	
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
	programme->transform();
}

void AutomateLutin::analyseStatique()
{
	AnalyseStatique analyseStatique(&tableSymboles, programme);

	analyseStatique.updateTableSymbole();
	analyseStatique.updateTableStatique();
	analyseStatique.check();
}

void AutomateLutin::execution()
{
	// TODO (version plus tard)
}

void AutomateLutin::affichage()
{
	programme->print();
}
