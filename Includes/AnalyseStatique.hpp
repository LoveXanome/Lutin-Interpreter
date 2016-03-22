#ifndef ANALYSE_STATIQUE_HPP
#define ANALYSE_STATIQUE_HPP

class Programme;

#include <string>

#include "Programme.hpp"
#include "Logger.hpp"
#include "StringHelper.hpp"
#include "EtatIdentifiant.hpp"
#include "Declaration.hpp"

#include "InstructionAffectation.hpp"
#include "InstructionLecture.hpp"
#include "InstructionEcriture.hpp"

class AnalyseStatique
{
public:
	AnalyseStatique(TableDesSymboles* tableDesSymboles, Programme* programme);
	virtual ~AnalyseStatique();

	// Realise l'analyse statique a l'aide des deux tables en attributs
	void check();

private:
	TableDesSymboles* tableDesSymboles;
	TableAnalyseStatique tableAnalyseStatique;
	Programme* programme;
	
	void fillTableSymboles();
	void fillTableStatique();

	void addSymboleToTableSymbole(const std::string& key, Declaration* value);
	bool symbolExists(const std::string& key);
	void printWarning(const std::string& msg) const;
	void throwError(const std::string& msg);
	void addEtatIdentifiantToTableStatique(const std::string& key, EtatIdentifiant* strucIdentifiant);
	
	void handleInstruction(Instruction* instruction);
	void handleInstructionAffectation(InstructionAffectation* affectation);
	void handleInstructionLecture(InstructionLecture* lecture);
	void handleInstructionEcriture(InstructionEcriture* ecriture);
	
	bool isVariable(const std::string& id) const;
	void checkVariable(const std::string& id, EtatIdentifiant* const etat);
	bool isConstant(const std::string& id) const;
	void checkConstant(const std::string& id, EtatIdentifiant* const etat);
	
	void deleteTableStatique();
	
	static const Logger logger;
};

#endif // ANALYSE_STATIQUE_HPP
