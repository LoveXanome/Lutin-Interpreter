#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "AnalyseStatique.hpp"
#include "Logger.hpp"

class Instruction
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
