#include "AutomateLutin.hpp"

#include "FileLexer.hpp"
#include "Programme.hpp"
#include "E0.hpp"
#include "LutinArgs.hpp"
#include "Identifiant.hpp"
#include "Valeur.hpp"
#include "SymboleTerminal.hpp"

AutomateLutin::AutomateLutin(const std::string& fileName, const int options)
{
	lexer = new FileLexer(fileName);
	
	symboles.push(new Programme);
	etats.push(new E0);
	
	this->options = options;
}

AutomateLutin::~AutomateLutin()
{
	while (!etats.empty())
	{
		delete etats.top();
		etats.pop();
	}
	
	while (!symboles.empty())
	{
		delete symboles.top();
		symboles.pop();
	}
	
	delete lexer;
}

void AutomateLutin::lecture()
{
	Symbole* firstSymbole = lexer->getNext();
	etats.top()->transition(this, firstSymbole);
	
	if (options & TRANSFORMATION)
		transformation();
	
	if (options & ANALYSE_STATIQUE)
		analyseStatique();
	
	if (options & EXECUTION)
		execution();
	
	if (options & AFFICHAGE)
		affichage();
}

void AutomateLutin::decalage(Symbole* symbole, Etat* etat, bool readNext)
{	
	symboles.push(symbole);
	etats.push(etat);
	
	if (readNext)
		symbole = lexer->getNext();
	
	etat->transition(this, symbole);
}

void AutomateLutin::reduction(Symbole* symbole, const unsigned int nbEtats)
{
	for (unsigned int i = 0; i < nbEtats; ++i)
		etats.pop();
		
	etats.top()->transition(this, symbole);
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
