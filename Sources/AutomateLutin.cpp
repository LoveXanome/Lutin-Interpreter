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

const Logger AutomateLutin::logger("AutomateLutin");

AutomateLutin::AutomateLutin(const std::string& fileName, const int options)
{
	lexer = new FileLexer(fileName);
	
	etats.push(new E0);
	
	this->options = options;
}

AutomateLutin::~AutomateLutin()
{
	logger.debug(StringHelper::format("Start destruction (%d etats & %d symboles)", etats.size(), symboles.size()));
	while (!etats.empty())
	{
		Etat* e = etats.top();
		etats.pop();
		delete e;
	}
	
	std::set<Symbole*> uniqueSymboles;
	while (!symboles.empty())
	{
		Symbole* s = symboles.top();
		symboles.pop();
		uniqueSymboles.insert(s);
	}
	
	for (Symbole* s : uniqueSymboles)
		delete s;
	
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
		
	logger.debug("Fin lecture");
}

valeurRetour AutomateLutin::decalage(Symbole* symbole, Etat* etat, bool readNext)
{	
	logger.debug(StringHelper::format("Decalage vers etat %s (symbole %s) (read next : %d)", etat->toString().c_str(), symbole->toString().c_str(), readNext));
	
	symboles.push(symbole);
	etats.push(etat);
	
	if (readNext)
		symbole = lexer->getNext();
	
	return etat->transition(this, symbole);
}

valeurRetour AutomateLutin::reduction(Symbole* symbole, const unsigned int nbEtats)
{
	for (unsigned int i = 0; i < nbEtats; ++i)
		etats.pop();
		
	return etats.top()->transition(this, symbole);
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
