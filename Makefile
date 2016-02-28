SRCDIR=Sources/
INCDIR=Includes/
BUILDDIR=Objects/
EXE=lut

FILES=AutomateLutin
SRC=$(addprefix $(SRCDIR), $(addsuffix .cpp, $(FILES)))
INC=$(addprefix $(INCDIR), $(addsuffix .hpp, $(FILES)))
OBJ=$(addprefix $(BUILDDIR), $(addsuffix .o, $(FILES)))

COMP=g++
COMPFLAGS=-Wall

all: builddir lutin
    
lutin: $(OBJ)
    $(COMP) $(COMPFLAGS) -o $(EXE) $(OBJ)
    
%.o : TODO
    
builddir:
    mkdir $(BUILDDIR)

.PHONY: clean
clean:
    rm -rf $(BUILDDIR) $(EXE)
