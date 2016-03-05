#include "LutinArgsFabric.hpp"

#include "StringHelper.hpp"
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
			std::string errorMsg = StringHelper::format("Invalid option '%c'", option);
			throw std::invalid_argument(errorMsg);
	}
}
