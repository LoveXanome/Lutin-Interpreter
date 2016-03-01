#ifndef TABLE_DES_SYMBOLES_HPP
#define TABLE_DES_SYMBOLES_HPP

#include <map>
#include <string>
#include "Declaration.hpp"

class TableDesSymboles : public std::map<std::string, Declaration>
{
public:
	TableDesSymboles();
	virtual ~TableDesSymboles();
};

#endif // TABLE_DES_SYMBOLES_HPP
