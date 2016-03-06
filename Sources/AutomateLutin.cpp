#include "AutomateLutin.hpp"

#include "FileLexer.hpp"
#include "Programme.hpp"
#include "E0.hpp"
#include "LutinArgs.hpp"

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
	/*Symbole* nextSymbole = lexer->getNext();
	etats.top()->transition(this, nextSymbole);*/
	
	if (options & TRANSFORMATION)
		transformation();
	
	if (options & ANALYSE_STATIQUE)
		analyseStatique();
	
	if (options & EXECUTION)
		execution();
	
	if (options & AFFICHAGE)
		affichage();
}

void AutomateLutin::decalage(Symbole* symbole, Etat* etat)
{
	symboles.push(symbole);
	etats.push(etat);
	
	Symbole* nextSymbole = lexer->getNext();
	etat->transition(this, nextSymbole);
}

void AutomateLutin::reduction(Etat* etat, const unsigned int nb)
{
	// ???
	etats.push(etat);
	for (unsigned int i = 0; i < nb; ++i)
		etats.pop();
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
