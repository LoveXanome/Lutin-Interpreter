#include "AnalyseStatique.hpp"
#include <iostream>

AnalyseStatique::AnalyseStatique(std::unordered_map<std::string, Declaration*>* tableDesSymboles, std::unordered_map<std::string, EtatIdentifiant>* tableAnalyseStatique) 
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
