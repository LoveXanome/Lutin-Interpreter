#include "AnalyseStatique.hpp"
#include "DeclarationVariable.hpp"
#include "DeclarationConstante.hpp"

#include <iostream> 
#include <string>


AnalyseStatique::AnalyseStatique() 
{
		
}

AnalyseStatique::~AnalyseStatique() 
{
	
}

void AnalyseStatique::check(std::unordered_map<std::string, Declaration*> tableDesSymboles, std::unordered_map<std::string, EtatIdentifiant> tableAnalyseStatique)
{

	for (auto it1=tableDesSymboles.begin(); it1!=tableDesSymboles.end(); ++it1)
	{
		for (auto it2=tableAnalyseStatique.begin(); it2!=tableAnalyseStatique.end(); ++it2)
		{
			if (it1->first == it2->first)
			{
				//Variable
				if (dynamic_cast<DeclarationVariable*>(it1->second)!=NULL)
				
				{
					//if(it2->second.declaree ==1)
				}
				//Constante
				else if(dynamic_cast<DeclarationConstante*>(it1->second)!=NULL)
				{
				}
			}
			//else 
			//throw runcout<<"error string tableDesSymboles non present dans tableAnalyseStatique"<<end;	
					
		}
	}	
}
