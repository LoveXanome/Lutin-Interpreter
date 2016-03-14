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
		addSymbole(declaration->getId(), declaration);
	}
}

/**
*	Parcours les instructions
		Mets a jour les bool affectee & utilisee de la table analyse statique
*/
void AnalyseStatique::updateTableStatique()
{
	// ListeInstructions* instructions = programme->getInstructions();

	// for (Instruction* instruction : *instructions)
	// {
	// 	std::cout << *instruction << std::endl;
	// }
}

void AnalyseStatique::checkSymbole(std::string key)
{
	auto search = tableDesSymboles->find(key);
	if ( search != tableDesSymboles->end() )
	{
		throw std::runtime_error(StringHelper::format("INTERPRETATION ERROR : Identifiant <%s> already used !", key.c_str()));
	}
}

void AnalyseStatique::addSymbole(std::string key, Declaration* value)
{
	checkSymbole(key);
	tableDesSymboles->insert(std::pair<std::string, Declaration*>(key,value));
}

void AnalyseStatique::addEtatIdentifiant()
{

}


