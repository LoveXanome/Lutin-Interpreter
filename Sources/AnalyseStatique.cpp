#include "AnalyseStatique.hpp"
#include <iostream>

AnalyseStatique::AnalyseStatique(TableDesSymboles* tableDesSymboles, TableAnalyseStatique* tableAnalyseStatique) 
{
	this->tableDesSymboles = tableDesSymboles;
	this->tableAnalyseStatique = tableAnalyseStatique;
}

AnalyseStatique::~AnalyseStatique() 
{}

bool AnalyseStatique::check()
{
	bool programmeValide = false;
	return programmeValide;
}

const Logger AnalyseStatique::logger("AnalyseStatique");

void AnalyseStatique::updateTableSymbole()
{
	ListeInstructions* listIns = programme->getInstructions();
	for (Instruction* ins : *listIns)
	{
		std::cout << *ins << std::endl;
	}
}
