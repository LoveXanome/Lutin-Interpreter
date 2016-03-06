SRCDIR=Sources/
INCDIR=Includes/
BUILDDIR=Objects/
EXE=lut

STATE_FILES=Etat E0 E1 28 29
GENERAL_FILES=AutomateLutin Programme Lexer FileLexer LineLexer Symbole CommandLineParser LutinArgsFabric StringHelper SymbolFabric SymboleTerminal RegexHelper
INSTRUCTION_FILES=Instruction InstructionAffectation InstructionEcriture InstructionLecture
DECLARATION_FILES=Declaration DeclarationConstante DeclarationVariable
EXPRESSION_FILES=Expression ExpressionBinaire ExpressionAddition ExpressionSoustraction ExpressionMultiplication ExpressionDivision Identifiant Valeur
FILES=$(GENERAL_FILES) $(STATE_FILES) $(INSTRUCTION_FILES) $(DECLARATION_FILES) $(EXPRESSION_FILES)

SRC=$(addprefix $(SRCDIR), $(addsuffix .cpp, $(FILES)))
INC=$(addprefix $(INCDIR), $(addsuffix .hpp, $(FILES)))
OBJ=$(addprefix $(BUILDDIR), $(addsuffix .o, $(FILES)))
MAIN=$(SRCDIR)main.cpp

COMP=@g++
LINKER=@g++
COMMONFLAGS=-std=c++11
COMPFLAGS=$(COMMONFLAGS) -Wall -Werror
LINKERFLAGS=$(COMMONFLAGS)
ECHO=@echo

all: builddir lutin

remake: clean all

$(BUILDDIR)%.o : $(SRCDIR)%.cpp
	$(ECHO) "Compiling $< (generating $@)"
	$(COMP) -o $@ -c $< $(COMPFLAGS) -I $(INCDIR)

main.o: $(MAIN)
	$(ECHO) "Compiling $(MAIN)"
	$(COMP) -o $(BUILDDIR)main.o -c $(MAIN) $(COMPFLAGS) -I $(INCDIR)

lutin: main.o $(OBJ)
	$(ECHO) "Linking $(EXE)"
	$(LINKER) $(LINKERFLAGS) -o $(EXE) $(OBJ) $(BUILDDIR)main.o $(INC)

builddir:
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(EXE)
