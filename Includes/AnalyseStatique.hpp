
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
    bool declaratee;
    bool affectee;
    bool utilisee;
} EtatIdentifiant;

typedef std::unordered_map<std::string, Declaration*> TableDesSymboles; 
typedef std::unordered_map<std::string, EtatIdentifiant> TableAnalyseStatique;

class AnalyseStatique
{
	public:
		AnalyseStatique(TableDesSymboles* tableDesSymboles, TableAnalyseStatique* tableAnalyseStatique);
		virtual ~AnalyseStatique();

		void updateTableSymbole();

		bool check();

	private:
		TableDesSymboles* tableDesSymboles;
		TableAnalyseStatique* tableAnalyseStatique;
		Programme* programme;

		static const Logger logger;

};
#endif // AUTOMATE_LUTIN_HPP
