#include "AnalyseStatique.hpp"

AnalyseStatique::AnalyseStatique(std::unordered_map<std::string, Declaration*>* tableDesSymboles, std::unordered_map<std::string, EtatIdentifiant>* tableAnalyseStatique) 
{
	this->tableDesSymboles = tableDesSymboles;
	this->tableAnalyseStatique = tableAnalyseStatique;
}

AnalyseStatique::~AnalyseStatique() 
{}

bool AnalyseStatique::check()
{
	bool programmeValide = false;
	return programmeValide;
}
