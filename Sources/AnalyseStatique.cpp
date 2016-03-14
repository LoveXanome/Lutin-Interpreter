#include "AnalyseStatique.hpp"
#include "DeclarationVariable.hpp"
#include "DeclarationConstante.hpp"

#include <iostream> 
#include <string>


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
	for (auto it1=tableDesSymboles->begin(); it1!=tableDesSymboles->end(); ++it1)
	{
		for (auto it2=tableAnalyseStatique.begin(); it2!=tableAnalyseStatique.end(); ++it2)
		{
			if (it1->first == it2->first)
			{
				//Variable
				if (dynamic_cast<DeclarationVariable*>(it1->second)!=NULL)
				
				{
					//si declarer ok,  affecté ok, utilisé ok
					if(it2->second.declaree ==1&&it2->second.affectee ==1&&it2->second.utilisee ==1)
					{

					}
					
				}
				//Constante
				else if(dynamic_cast<DeclarationConstante*>(it1->second)!=NULL)
				{

				}
			}
			else 
			{
				throw std::runtime_error("error string tableDesSymboles non present dans tableAnalyseStatique");					
			}
		}
	}	
}
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
