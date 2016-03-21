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
	
	logger.debug("== Show table analyse statique ==");
	for (auto it = tableAnalyseStatique.begin(); it != tableAnalyseStatique.end(); ++it)
		logger.debug(StringHelper::format("%s declared : %d / affected : %d / used : %d", it->first.c_str(), it->second->isDeclared(), it->second->isAffected(), it->second->isUsed()));
	
	logger.construction("End of construction");
}

AnalyseStatique::~AnalyseStatique() 
{
	logger.destruction("Deleting table analyse statique");
	for (auto map_it = tableAnalyseStatique.begin(); map_it != tableAnalyseStatique.end() ; ++map_it)
		delete map_it->second;
}

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
		std::string key = declaration->getIdentifiant();
		if (symbolExists(key))
			printWarning(StringHelper::format("Identifiant '%s' declared more than once", key.c_str()));
		else
		{
			logger.debug(StringHelper::format("adding %s to symbols", key.c_str()));
			addSymboleToTableSymbole(key, declaration);

			logger.debug(StringHelper::format("adding %s to 'table statique'", key.c_str()));
			EtatIdentifiant* etat = new EtatIdentifiant;
			addEtatIdentifiantToTableStatique(key, etat);
			
			logger.debug(StringHelper::format("%s added !", key.c_str()));
		}
	}
}

void AnalyseStatique::addSymboleToTableSymbole(const std::string& key, Declaration* value)
{	
	tableDesSymboles->insert(pairSymbole(key, value));
}

bool AnalyseStatique::symbolExists(const std::string& key)
{
	auto search = tableDesSymboles->find(key);
	return search != tableDesSymboles->end();
}

void AnalyseStatique::addEtatIdentifiantToTableStatique(const std::string& key, EtatIdentifiant* strucIdentifiant)
{
	tableAnalyseStatique.insert(pairAnalyse(key, strucIdentifiant));
}

/**
*	Parcours les instructions
		Mets a jour les bool affectee & utilisee de la table analyse statique
*/
void AnalyseStatique::fillTableStatique()
{
	ListeInstructions* instructions = programme->getInstructions();

	for (Instruction* instruction : *instructions)
		handleInstruction(instruction);
}

void AnalyseStatique::handleInstruction(Instruction* instruction)
{
	if (InstructionAffectation* affectation = dynamic_cast<InstructionAffectation*>(instruction))
		handleInstructionAffectation(affectation);
		
	else if (InstructionLecture* lecture = dynamic_cast<InstructionLecture*>(instruction))
		handleInstructionLecture(lecture);
		
	else if (InstructionEcriture* ecriture = dynamic_cast<InstructionEcriture*>(instruction))
		handleInstructionEcriture(ecriture);
		
	else
		throw std::runtime_error("Unexpected error: instruction could not be casted to any derived type (should never reach this code).");
}

void AnalyseStatique::handleInstructionAffectation(InstructionAffectation* affectation)
{
	logger.debug("Handle instruction affectation");

	// S'il y a des identifiants dans l'expression, ils sont utilisés
	for (std::string ident : affectation->getIdentifiantsInExpression())
	{
		if (symbolExists(ident))
		{
			if(tableAnalyseStatique[ident]->isAffected())
				tableAnalyseStatique[ident]->use();
			else
				throwError(StringHelper::format("Using unaffected variable %s in affectation expression", ident.c_str()));
		}
		else
			throwError(StringHelper::format("Using undeclared variable %s in affectation expression", ident.c_str()));
	}
	
	// Identifiant à gauche est affecté
	std::string identifiant = affectation->getIdentifiant();
	if (symbolExists(identifiant))
		//	TODO : handle error affecting const
		tableAnalyseStatique[identifiant]->affect();
	else
		throwError(StringHelper::format("Affecting undeclared variable %s", identifiant.c_str()));
}

void AnalyseStatique::handleInstructionLecture(InstructionLecture* lecture)
{
	logger.debug("Handle instruction lecture");
	
	// Identifiant est affecté
	std::string identifiant = lecture->getIdentifiant();
	if (symbolExists(identifiant))
		tableAnalyseStatique[identifiant]->affect();
	else
		throwError(StringHelper::format("Reading undeclared variable %s", identifiant.c_str()));
}

void AnalyseStatique::handleInstructionEcriture(InstructionEcriture* ecriture)
{
	logger.debug("Handle instruction ecriture");
	
	// S'il y a des identifiants dans l'expression, il sont utilisés
	for (std::string ident : ecriture->getIdentifiantsInExpression())
		if (symbolExists(ident))
			tableAnalyseStatique[ident]->use();
		else
			throwError(StringHelper::format("Using undeclared variable %s in writing expression", ident.c_str()));
}



void AnalyseStatique::check()
{
	for (auto it = tableAnalyseStatique.begin(); it != tableAnalyseStatique.end(); ++it)
	{
		if (isVariable(it->first))
			checkVariable(it->first, it->second);
 
		else if (isConstant(it->first))
			checkConstant(it->first, it->second);
	}
}

bool AnalyseStatique::isVariable(const std::string& id) const
{
	Declaration* d = tableDesSymboles->at(id);
	return dynamic_cast<DeclarationVariable*>(d);
}

void AnalyseStatique::checkVariable(const std::string& id, EtatIdentifiant* const etat) const
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
	if (!etat->isDeclared())
	{
		// TODO : Traitement du non decare, non affecte, non utilise ?
		throwError(StringHelper::format("Undeclared variable %s", id.c_str()));
	}
	else // erreur/warning/OK selon "affected" ou "used" d'une variable "declared"
	{
		if (!etat->isAffected() && !etat->isUsed())
			printWarning(StringHelper::format("%s declared but not affected nor used", id.c_str()));

		else if (!etat->isAffected() && etat->isUsed())
			printWarning(StringHelper::format("%s declared and used but not affected (undefined behavior)", id.c_str()));

		else if (etat->isAffected() && !etat->isUsed())
			printWarning(StringHelper::format("%s declared and affected but not used", id.c_str()));
	}
}


bool AnalyseStatique::isConstant(const std::string& id) const
{
	Declaration* d = tableDesSymboles->at(id);
	return dynamic_cast<DeclarationConstante*>(d);
}

void AnalyseStatique::checkConstant(const std::string& id, EtatIdentifiant* const etat) const
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
	if (!etat->isDeclared())
	{
		throwError(StringHelper::format("Undeclared constant %s", id.c_str())); 
	}
	else
	{
		// Constante affecté --> pas le droit
		if (etat->isAffected())
			throwError(StringHelper::format("Affecting constant %s", id.c_str()));
				
		else if (!etat->isUsed())
			printWarning(StringHelper::format("%s declared but not used", id.c_str()));
	}
}

void AnalyseStatique::printWarning(const std::string& msg) const
{
	std::cerr << "WARN: " << msg << std::endl;
}

void AnalyseStatique::throwError(const std::string& msg) const
{
	throw std::runtime_error("ERR: " + msg);
}
