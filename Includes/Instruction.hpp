#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "Symbole.hpp"
#include "Logger.hpp"

class Instruction : public Symbole
{
public:
	Instruction();
	virtual ~Instruction();
	virtual void print() const = 0;
private:
	static const Logger logger;
};

#endif // INSTRUCTION_HPP
