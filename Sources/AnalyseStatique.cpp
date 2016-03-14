#include "AnalyseStatique.hpp"
#include <iostream>

AnalyseStatique::AnalyseStatique() 
{	
}
AnalyseStatique::~AnalyseStatique() 
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
