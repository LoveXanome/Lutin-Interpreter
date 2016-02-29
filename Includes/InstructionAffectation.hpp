#ifndef INSTRUCTION_AFFECTATION_HPP
#define INSTRUCTION_AFFECTATION_HPP

#include <iostream>
#include <string>

using namespace std;

class InstructionAffectation
{
	public:
	 InstructionAffectation(string identifiant);
	 virtual ~InstructionAffectation();
	 
	 string getIdentifiant();
	 void setIdentifiant(string identifiant);
	
	private:
	 string identifiant;
};

#endif
