#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "Symbole.hpp"

class Instruction : public Symbole
{
public:
	Instruction();
	virtual ~Instruction();
	virtual void print() const = 0;
};

#endif // INSTRUCTION_HPP
