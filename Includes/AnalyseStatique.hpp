#ifndef ANALYSE_STATIQUE_HPP
#define ANALYSE_STATIQUE_HPP

class Programme;

#include "Declaration.hpp"

#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, Declaration*> TableDesSymboles; 
typedef std::pair<std::string, Declaration*> pairSymbole; 

#include "Programme.hpp"
#include "Logger.hpp"
#include "StringHelper.hpp"

//structure pour analyse statique
typedef struct etatIdentifiant
{
	bool declared;
    bool affected;
    bool used;

    etatIdentifiant(bool declared, bool affected, bool used)
    {
    	this->declared = declared;
    	this->affected = affected;
    	this->used = used;
    }

    std::string toString() const
    {
    	std::string res ("Declared=");
    	declared ? res+="true" : res+="false";
    	res+=" ; Affected=";
    	affected ? res+="true" : res+="false";
    	res+=" ; Used=";
    	used ? res+="true" : res+="false";

    	return res;
    }
} EtatIdentifiant;

//	Used for method setEtat
enum etats {
	DECLAREE,
	AFFECTEE,
	UTILISEE
};

typedef std::unordered_map<std::string, EtatIdentifiant> TableAnalyseStatique;
typedef std::pair<std::string, EtatIdentifiant> pairAnalyse; 

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
	void addEtatIdentifiantToTableStatique(const std::string& key, EtatIdentifiant* strucIdentifiant);
	
	//	Check if symbole was already declared
	void setEtat(etats* etat, EtatIdentifiant* strucIdentifiant);
	
	static const Logger logger;
};
#endif // ANALYSE_STATIQUE_HPP
