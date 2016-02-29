SRCDIR=Sources/
INCDIR=Includes/
BUILDDIR=Objects/
EXE=lut

FILES=AutomateLutin
SRC=$(addprefix $(SRCDIR), $(addsuffix .cpp, $(FILES)))
INC=$(addprefix $(INCDIR), $(addsuffix .hpp, $(FILES)))
OBJ=$(addprefix $(BUILDDIR), $(addsuffix .o, $(FILES)))
MAIN=$(SRCDIR)main.cpp

COMP=g++
COMPFLAGS=-Wall

all: builddir lutin

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
