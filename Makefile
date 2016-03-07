SRCDIR=Sources/
INCDIR=Includes/
BUILDDIR=Objects/
EXE=lut

#STATE_FILES=Etat E0 E1 E2 E3 E4 E5 E6 E7 E8 E9 E10 E11 E12 E13 E14 E15 E16 E17 E18 E19 E20 E21 E22 E23 E24 E25 E26 E27 E28 E29 E30 E31 E32 E33 E34 E35 E36 E37 E38 E39 E40 E41 E42 E43
STATE_FILES=Etat E0 E1 E2 E3 E4 E5 E6 E27 E28 E29 E30 E31 E32 E33 E34 E35 E36 E37 E38 E39 E40 E41 E42 E43
GENERAL_FILES=AutomateLutin Programme Lexer FileLexer LineLexer Symbole CommandLineParser LutinArgsFabric StringHelper SymbolFabric SymboleTerminal RegexHelper SymboleDefaut
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
