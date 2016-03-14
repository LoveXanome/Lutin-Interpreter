#include "AnalyseStatique.hpp"
#include <iostream>

const Logger AnalyseStatique::logger("AnalyseStatique");

AnalyseStatique::AnalyseStatique(TableDesSymboles* tableDesSymboles, Programme* programme) 
{
	this->tableDesSymboles = tableDesSymboles;
	this->programme = programme;
}

AnalyseStatique::~AnalyseStatique() 
{}

void AnalyseStatique::check()
{

}


/**
*	Parcours les declarations
		Mets a jour la table des symboles
		& le bool declare de la table analyse statique
*/
void AnalyseStatique::updateTableSymbole()
{
	ListeDeclarations* declarations = programme->getDeclarations();
	
	for (Declaration* declaration : *declarations)
	{
		std::cout << *declaration << std::endl;
	}
}

/**
*	Parcours les instructions
		Mets a jour les bool affectee & utilisee de la table analyse statique
*/
void AnalyseStatique::updateTableStatique()
{
	ListeInstructions* instructions = programme->getInstructions();

	for (Instruction* instruction : *instructions)
	{
		std::cout << *instruction << std::endl;
	}
}

void AnalyseStatique::checkSymbole()
{

}

void AnalyseStatique::addSymbole(std::string key, Declaration* value)
{
	checkSymbole();
	tableDesSymboles->insert(std::pair<std::string, Declaration*>(key,value));
}

void AnalyseStatique::addEtatIdentifiant()
{

}


