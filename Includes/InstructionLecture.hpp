#ifndef INSTRUCTION_LECTURE_HPP
#define INSTRUCTION_LECTURE_HPP

#include "Instruction.hpp"
#include <string>

class InstructionLecture : public Instruction
{
public:
	InstructionLecture(const std::string& identifiant);
	virtual ~InstructionLecture();
	void print() const;

private:
	std::string identifiant;
};

#endif // INSTRUCTION_LECTURE_HPP
