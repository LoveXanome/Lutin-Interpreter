SRCDIR=Sources/
INCDIR=Includes/
BUILDDIR=Objects/
EXE=lut

STATE_FILES=Etat E0
GENERAL_FILES=AutomateLutin Programme Lexer TableDesSymboles Symbole CommandLineParser LutinArgsFabric StringHelper
INSTRUCTION_FILES=Instruction InstructionAffectation InstructionEcriture InstructionLecture ListeInstructions
DECLARATION_FILES=Declaration DeclarationConstante DeclarationVariable ListeDeclarations
EXPRESSION_FILES=Expression ExpressionBinaire ExpressionAddition ExpressionSoustraction ExpressionMultiplication ExpressionDivision
FILES=$(GENERAL_FILES) $(STATE_FILES) $(INSTRUCTION_FILES) $(DECLARATION_FILES) $(EXPRESSION_FILES)

SRC=$(addprefix $(SRCDIR), $(addsuffix .cpp, $(FILES)))
INC=$(addprefix $(INCDIR), $(addsuffix .hpp, $(FILES)))
OBJ=$(addprefix $(BUILDDIR), $(addsuffix .o, $(FILES)))
MAIN=$(SRCDIR)main.cpp

COMP=g++
COMPFLAGS=-Wall -Werror -std=c++11

all: builddir lutin

remake: clean all

$(BUILDDIR)%.o : $(SRCDIR)%.cpp
	$(COMP) -o $@ -c $< $(COMPFLAGS) -I $(INCDIR)

main.o: $(MAIN)
	$(COMP) -o $(BUILDDIR)main.o -c $(MAIN) $(COMPFLAGS) -I $(INCDIR)

lutin: main.o $(OBJ)
	$(COMP) $(COMPFLAGS) -o $(EXE) $(OBJ) $(BUILDDIR)main.o $(INC)

builddir:
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(EXE)
