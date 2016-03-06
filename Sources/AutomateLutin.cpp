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

void AutomateLutin::decalage(Symbole* symbole, Etat* etat)
{
	// Empiler seulement les symboles "utiles"
	// Peut-être mettre les instructions / declarations dans un attribut "Programme"
	// Donc méthodes addIntructionToProgram() & addDeclarationToProgram() ?
	
	// Quand est-ce qu'on dépile les symboles? Sert à quoi cette liste?
	
	// Si symbole non terminal a fait la transitio
	// -> ne pas lire le prochaine symbole du fichier
	// Sinon, faire un getNext()
	
	//symboles.push(symbole);
	etats.push(etat);
	
	Symbole* nextSymbole = lexer->getNext();
	etat->transition(this, nextSymbole);
}

void AutomateLutin::reduction(Symbole* symbole, const unsigned int nb)
{
	symboles.push(symbole);
	
	for (unsigned int i = 0; i < nb; ++i)
		etats.pop();
		
	etats.top()->transition(this, symbole);
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
