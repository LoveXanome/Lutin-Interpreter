#ifndef LISTE_INSTRUCTIONS_HPP
#define LISTE_INSTRUCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Instruction.hpp"

using namespace std;

class ListeInstructions
{ 
	public:
	 ListeInstructions();
	 virtual ~ListeInstructions();
	 
	 void addInstruction(Instruction instruction);
	 vector<Instruction>::iterator getIterator();
	
	private:
		vector<Instruction> vInstructions;
};

#endif
