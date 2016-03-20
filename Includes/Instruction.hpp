#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "Symbole.hpp"
#include "TypeDefinitions.hpp"
#include "Logger.hpp"

class Instruction : public Symbole
{
public:
	Instruction();
	virtual ~Instruction();
	virtual void print() const = 0;
	virtual void transform() = 0;
	virtual void exec(TableDesSymboles& tableDesSymboles) = 0;
private:
	static const Logger logger;
};

#endif // INSTRUCTION_HPP
