
#ifndef ANALYSESTATIQUE_HPP
#define ANALYSESTATIQUE_HPP

#include <string>

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
	private:
};
#endif // AUTOMATE_LUTIN_HPP