#ifndef TYPE_DEFINITIONS_HPP
#define TYPE_DEFINITIONS_HPP

#include <string>
#include <unordered_map>
#include "Declaration.hpp"
#include "EtatIdentifiant.hpp"

typedef std::unordered_map<std::string, Declaration*> TableDesSymboles; 
typedef std::pair<std::string, Declaration*> pairSymbole; 

typedef std::unordered_map<std::string, EtatIdentifiant*> TableAnalyseStatique;
typedef std::pair<std::string, EtatIdentifiant*> pairAnalyse; 

#endif // TYPE_DEFINITIONS_HPP
