#include "AutomateLutin.hpp"

#include <iostream>

#include "Programme.hpp"
#include "E0.hpp"

AutomateLutin::AutomateLutin(const std::string& fileName, const int options)
{
	lexer = new Lexer(fileName);
	
	symboles.push(new Programme);
	etats.push(new E0);
	
	// options
}

AutomateLutin::~AutomateLutin()
{
	delete lexer;
}

void AutomateLutin::lecture()
{
	// TODO
	std::cout << "LECTURE" << std::endl;
}

void AutomateLutin::decalage(Symbole* symbole, Etat* etat)
{
}

void AutomateLutin::reduction(Etat* etat, int nb)
{
}
