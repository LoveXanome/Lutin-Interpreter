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
				// Variable
				if (dynamic_cast<DeclarationVariable*>(it1->second)!=NULL)
				{
					/* non delcaree, non affectee, non utilisee --> pas possible
					 * non declaree, non affectee, utilisee --> erreur
					 * non declaree, affectee, non utilisee --> erreur
					 * non delcaree, affectee, utilisee --> erreur
					 * declaree, non affectee, non utilisee --> warning
					 * declaree, non affectee, utilisee --> erreur
					 * declaree, affectee, non utilisee --> warning
					 * declaree, affectee, utilisee --> it's all good
					 */
					  
					// Variable non declaree => erreur
					if(!it2->second.declared)
					{
						// TODO : Traitement du non decare, non affecte, non utilise ?

						throw std::runtime_error(StringHelper::format("Error : Undeclared variable %s.",
													it1->first.c_str())); // already string, don't need toString()
					}

					// erreur/warning/OK selon "affected" ou "used" d'une variable "declared"
					else
					{
						if(!it2->second.affected && !it2->second.used)
						{
							throw std::runtime_error(StringHelper::format("Warning : %s declared but not affected nor used.",
													it1->first.c_str())); // already string, don't need toString()
						}

						else if(!it2->second.affected && it2->second.used)
						{
							throw std::runtime_error(StringHelper::format("Error : %s declared and used but not affected.",
													it1->first.c_str())); // already string, don't need toString()
						}

						else if(it2->second.affected && !it2->second.used)
						{
							throw std::runtime_error(StringHelper::format("Warning : %s declared and affected but not used.",
													it1->first.c_str())); // already string, don't need toString()
						}

						// Dernier cas : variable "declared", "affected" et "used"
						else
						{
							std::cout << it1->first.c_str() << "OK : declared, affected and used." << std::endl;
						}
					}
					
				}

				// Constante
				else if(dynamic_cast<DeclarationConstante*>(it1->second)!=NULL)
				{

				}
			}

			else 
			{
				throw std::runtime_error("Error : id (string) of tableDesSymboles does not exist in tableAnalyseStatique.");					
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

		//	Specify id declared
		EtatIdentifiant etat (true, false, false);
		addEtatIdentifiant(declaration->getId(), &etat);
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

void AnalyseStatique::checkSymbole(std::string* key)
{
	auto search = tableDesSymboles->find(*key);
	if ( search != tableDesSymboles->end() )
	{
		throw std::runtime_error(StringHelper::format("INTERPRETATION ERROR : Identifiant <%s> already used !", key->c_str()));
	}
}

void AnalyseStatique::addSymbole(std::string* key, Declaration* value)
{
	checkSymbole(key);
	tableDesSymboles->insert(pairSymbole(*key,value));
}


void AnalyseStatique::addEtatIdentifiant(std::string* key, EtatIdentifiant* strucIdentifiant)
{
	tableAnalyseStatique.insert(pairAnalyse(*key, *strucIdentifiant));
}

void AnalyseStatique::setEtat(etats* etat, EtatIdentifiant* strucIdentifiant)
{
	switch(*etat)
	{
		case DECLAREE:
			strucIdentifiant->declared = true;
			break;

		case AFFECTEE:
			strucIdentifiant->affected = true;
			break;

		case UTILISEE:
			strucIdentifiant->used = true;
			break;

		default :
			throw std::runtime_error("ERROR : Incorrect call to AnalyseStatique::setEtat !");
			break;
	}
}

void AnalyseStatique::print() const
{
	std::cout << "DISPLAY TableDesSymboles :\n";
	for (auto it1=tableDesSymboles->begin(); it1!=tableDesSymboles->end(); ++it1)
	{
		std::cout << "id = " << it1->first << " | " << it1->second->getType() << std::endl;
	}
		
	std::cout << "DISPLAY tableAnalyseStatique :\n";
	for (auto it2=tableAnalyseStatique.begin(); it2!=tableAnalyseStatique.end(); ++it2)
	{
		std::cout << "id = " << it2->first << " | " << it2->second.toString() << std::endl;
	}
}
