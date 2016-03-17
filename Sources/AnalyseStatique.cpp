#include "AnalyseStatique.hpp"

#include "DeclarationVariable.hpp"
#include "DeclarationConstante.hpp"

#include <iostream> 
#include <string>

const Logger AnalyseStatique::logger("AnalyseStatique");	

AnalyseStatique::AnalyseStatique(TableDesSymboles* tableDesSymboles, Programme* programme) : tableDesSymboles(tableDesSymboles), programme(programme)
{
	logger.construction("Construction");
	fillTableSymboles();
	fillTableStatique();
	logger.construction("End of construction");
}

AnalyseStatique::~AnalyseStatique() 
{}

/**
*	Parcours les declarations
		Mets a jour la table des symboles
		& le bool declare de la table analyse statique
*/
void AnalyseStatique::fillTableSymboles()
{
	logger.debug("Fill table symbole");
	ListeDeclarations* declarations = programme->getDeclarations();
	
	for (Declaration* declaration : *declarations)
	{
		logger.debug(StringHelper::format("adding %s to symbols", declaration->getIdentifiant().c_str()));
		addSymboleToTableSymbole(declaration->getIdentifiant(), declaration);

		/*logger.debug(StringHelper::format("adding %s to 'table statique'", declaration->getIdentifiant().c_str()));
		//Specify id declared
		EtatIdentifiant etat(true, false, false); // TODO comme ça marchera pas muhaha
		addEtatIdentifiantToTableStatique(declaration->getIdentifiant(), &etat); // TODO comme ça ne marchera pas muhahaha */
		logger.debug(StringHelper::format("%s added !", declaration->getIdentifiant().c_str()));
	}
}

void AnalyseStatique::addSymboleToTableSymbole(const std::string& key, Declaration* value)
{
	if (symbolExists(key))
		throw std::runtime_error(StringHelper::format("Identifiant <%s> already used !", key.c_str()));
	
	tableDesSymboles->insert(pairSymbole(key, value));
}

bool AnalyseStatique::symbolExists(const std::string& key)
{
	auto search = tableDesSymboles->find(key);
	return search != tableDesSymboles->end();
}

void AnalyseStatique::addEtatIdentifiantToTableStatique(const std::string& key, EtatIdentifiant* strucIdentifiant)
{
	tableAnalyseStatique.insert(pairAnalyse(key, *strucIdentifiant));
}

/**
*	Parcours les instructions
		Mets a jour les bool affectee & utilisee de la table analyse statique
*/
void AnalyseStatique::fillTableStatique()
{
	// ListeInstructions* instructions = programme->getInstructions();

	// for (Instruction* instruction : *instructions)
	// {
	// 	std::cout << *instruction << std::endl;
	// }
}


void AnalyseStatique::check()
{
	for (auto it1 = tableDesSymboles->begin(); it1!=tableDesSymboles->end(); ++it1)
	{
		for (auto it2 = tableAnalyseStatique.begin(); it2!=tableAnalyseStatique.end(); ++it2)
		{
			if (it1->first == it2->first)
			{
				// Variable
				if (dynamic_cast<DeclarationVariable*>(it1->second)!=NULL)
				{
					/* non delcaree, non affectee, non utilisee --> pas possible
					 * non declaree, non affectee, utilisee --> erreur
					 * non declaree, affectee, non utilisee --> erreur
					 * non declaree, affectee, utilisee --> erreur
					 * declaree, non affectee, non utilisee --> warning
					 * declaree, non affectee, utilisee --> erreur (sûr ? pas juste warning, puis ça fera n'importe quoi je dirais)
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
					/* non delcaree, non affectee, non utilisee --> pas possible
					 * non declaree, non affectee, utilisee --> erreur
					 * non declaree, affectee, non utilisee --> erreur
					 * non declaree, affectee, utilisee --> erreur
					 * declaree, non affectee, non utilisee --> warning non utilise
					 * declaree, non affectee, utilisee --> ok
					 * declaree, affectee, non utilisee --> erreur (on peut pas affecter une constante)
					 * declaree, affectee, utilisee --> erreur (on peut pas affecter une constante)
					 */

					 // Constante non declaree => erreur
					if(!it2->second.declared)
					{
						throw std::runtime_error(StringHelper::format("Error : Undeclared constante %s.",
													it1->first.c_str())); 
					}
					else
					{
						// Constante affecté --> pas le droit
						if(it2->second.affected)
						{
							throw std::runtime_error(StringHelper::format("Error : Affected constante %s.",
														it1->first.c_str())); 
						}
						else
						{
							if(!it2->second.used)
							{
								throw std::runtime_error(StringHelper::format("Warning : %s declared but not used.",
													it1->first.c_str()));
							}
						}
					}
				}
			}
			else 
			{
				throw std::runtime_error("Error : id (string) of tableDesSymboles does not exist in tableAnalyseStatique.");					
			}
		}
	}	
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
