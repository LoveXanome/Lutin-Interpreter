
#ifndef ANALYSESTATIQUE_HPP
#define ANALYSESTATIQUE_HPP

#include <string>
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

class AnalyseStatique
{
	public:
		AnalyseStatique();
		virtual ~AnalyseStatique();

		void updateTableSymbole();

	private:
		Programme* programme;

		static const Logger logger;
};
#endif // AUTOMATE_LUTIN_HPP