
#ifndef ANALYSESTATIQUE_HPP
#define ANALYSESTATIQUE_HPP

#include "Declaration.hpp"

#include <string>
#include <unordered_map>

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

typedef std::unordered_map<std::string, Declaration*> TableDesSymboles; 
typedef std::pair<std::string, Declaration*> pairSymbole; 

typedef std::unordered_map<std::string, EtatIdentifiant> TableAnalyseStatique;
typedef std::pair<std::string, EtatIdentifiant> pairAnalyse; 

class AnalyseStatique
{
	public:
		AnalyseStatique(TableDesSymboles* tableDesSymboles, Programme* programme);
		virtual ~AnalyseStatique();

		void updateTableSymbole();

		void updateTableStatique();

		// Realise l'analyse statique a l'aide des deux tables en attributs
		// Pre-requis : tableDesSymboles et tableAnalyseStatique doivent avoir ete MAJ
		void check();

		//	Check if symbole was already declared
		void checkSymbole(std::string* key);

		void addSymbole(std::string* key, Declaration* value);

		void addEtatIdentifiant(std::string* key, EtatIdentifiant* strucIdentifiant);

		void setEtat(etats* etat, EtatIdentifiant* strucIdentifiant);

		void print() const;

	private:
		TableDesSymboles* tableDesSymboles;
		TableAnalyseStatique tableAnalyseStatique;
		Programme* programme;

		static const Logger logger;

		

};
#endif // AUTOMATE_LUTIN_HPP
