#include "Instruction.hpp"
#include "SymboleEnum.hpp"
#include "StringHelper.hpp"

const Logger Instruction::logger("Instruction");

Instruction::Instruction()
{
	logger.construction(StringHelper::format("Construction Instruction"));
}

Instruction::~Instruction()
{
	logger.destruction(StringHelper::format("Destruction Instruction"));	
}
