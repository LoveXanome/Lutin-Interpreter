#include "AnalyseStatique.hpp"
#include <iostream>

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

const Logger AnalyseStatique::logger("AnalyseStatique");

void AnalyseStatique::updateTableSymbole()
{
	ListeInstructions* listIns = programme->getInstructions();
	for (Instruction* ins : *listIns)
	{
		std::cout << *ins << std::endl;
	}
}

void AnalyseStatique::updateTableStatique()
{

}
