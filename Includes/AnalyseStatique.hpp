
#ifndef ANALYSESTATIQUE_HPP
#define ANALYSESTATIQUE_HPP

#include "Declaration.hpp"

#include <string>
#include <unordered_map>

//structure pour analyse statique
typedef struct etatIdentifiant
{
    bool declaratee;
    bool affectee;
    bool utilisee;
} EtatIdentifiant;

class AnalyseStatique
{
	public:
		AnalyseStatique(std::unordered_map<std::string, Declaration*>* tableDesSymboles, std::unordered_map<std::string, EtatIdentifiant>* tableAnalyseStatique);
		virtual ~AnalyseStatique();
		bool check();
	private:
		std::unordered_map<std::string, Declaration*>* tableDesSymboles;
		std::unordered_map<std::string, EtatIdentifiant>* tableAnalyseStatique;
};
#endif // AUTOMATE_LUTIN_HPP
