#include "LutinArgsFabric.hpp"

#include <cstdio>
#include <string>
#include <stdexcept>

LutinArgs LutinArgsFabric::makeLutinArg(const char option)
{
	switch (option)
	{
		case TRANSFORMATION_OPT:
			return TRANSFORMATION;
		case ANALYSE_STATIQUE_OPT:
			return ANALYSE_STATIQUE;
		case AFFICHAGE_OPT:
			return AFFICHAGE;
		case EXECUTION_OPT:
			return EXECUTION;
		default:
			char* tmpError = new char[19];
			sprintf(tmpError, "Invalid option '%c'", option);
			std::string errorMsg(tmpError);
			delete[] tmpError;
			
			throw std::invalid_argument(errorMsg);
	}
}
