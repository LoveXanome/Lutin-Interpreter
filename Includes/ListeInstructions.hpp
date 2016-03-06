#ifndef LISTE_INSTRUCTIONS_HPP
#define LISTE_INSTRUCTIONS_HPP

#include <vector>
#include "Instruction.hpp"

class ListeInstructions : public std::vector<Instruction>
{ 
public:
	ListeInstructions();
	virtual ~ListeInstructions();
};

#endif // LISTE_INSTRUCTIONS_HPP
