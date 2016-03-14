
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
    bool declaree;
    bool affectee;
    bool utilisee;

    etatIdentifiant(bool declared, bool affected, bool used)
    {
    	declaree = declared;
    	affectee = affected;
    	utilisee = used;
    }

} EtatIdentifiant;

//	Used for method setEtat
enum etats {
	DECLAREE,
	AFFECTEE,
	UTILISEE
};

typedef std::unordered_map<std::string, Declaration*> TableDesSymboles; 
typedef std::unordered_map<std::string, EtatIdentifiant> TableAnalyseStatique;

class AnalyseStatique
{
	public:
		AnalyseStatique(TableDesSymboles* tableDesSymboles, Programme* programme);
		virtual ~AnalyseStatique();

		void updateTableSymbole();

		void updateTableStatique();

		void check();

		//	Check if symbole was already declared
		void checkSymbole(std::string* key);

		void addSymbole(std::string* key, Declaration* value);

		void addEtatIdentifiant(std::string* key, EtatIdentifiant* strucIdentifiant);

		void setEtat(etats* etat, EtatIdentifiant* strucIdentifiant);

	private:
		TableDesSymboles* tableDesSymboles;
		TableAnalyseStatique tableAnalyseStatique;
		Programme* programme;

		static const Logger logger;

		

};
#endif // AUTOMATE_LUTIN_HPP
