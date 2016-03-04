#ifndef LUTIN_ARGS_FABRIC_HPP
#define LUTIN_ARGS_FABRIC_HPP

#include "LutinArgs.hpp"

class LutinArgsFabric
{
public:
	virtual ~LutinArgsFabric();
	static LutinArgs makeLutinArg(const char option);
	
private:
	LutinArgsFabric();
	static const char TRANSFORMATION_OPT = 'o';
	static const char ANALYSE_STATIQUE_OPT = 'a';
	static const char AFFICHAGE_OPT = 'p';
	static const char EXECUTION_OPT = 'e';
};

#endif // LUTIN_ARGS_FABRIC_HPP
