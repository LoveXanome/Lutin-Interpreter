
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
} EtatIdentifiant;

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

		void addSymbole(std::string key, Declaration* value);

		void addEtatIdentifiant();

		//	Check if symbole was already declared
		void checkSymbole(std::string key);

	private:
		TableDesSymboles* tableDesSymboles;
		TableAnalyseStatique tableAnalyseStatique;
		Programme* programme;

		static const Logger logger;

};
#endif // AUTOMATE_LUTIN_HPP
