# makefile generico per l'esercitazione di aps

# chiama dal terminale
# make target prog=nome_del_programma
CC = g++

SRCDIR = src
OBJDIR = obj
HDRDIR = include

CFLAGS = -Wall -Wfatal-errors

# il progetto ha il nome della cartella
BINARY := $(shell basename "$(CURDIR)")

all: $(BINARY)

STRUCTURE := $(shell find $(SRCDIR) -type d)

CODEFILES := $(addsuffix /*,$(STRUCTURE))
CODEFILES := $(wildcard $(CODEFILES))

SRCFILES := $(filter %.cpp,$(CODEFILES))
HDRFILES := $(filter %.hpp,$(CODEFILES))
OBJFILES := $(subst $(SRCDIR),$(OBJDIR),$(SRCFILES:%.cpp=%.o))

LIBDEPS := $(filter-out $(OBJDIR)/main.o,$(OBJFILES))


compile: $(OBJFILES)

# make ha bisogno di indentazioni col tab non spazi
$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/,%.cpp %.hpp)
	$(CC) -c $< -o $@ $(CFLAGS) 

clean:
	-rm -r $(OBJDIR)/*