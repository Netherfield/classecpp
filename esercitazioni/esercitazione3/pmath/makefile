
PROJECT := Poli
HDRDIR := include
SRCDIR := src
OBJDIR := obj


CFLAGS := -c -Wall -Wfatal-errors

$(PROJECT): $(PROJECT).o main.o
	g++ -o $(PROJECT) $(PROJECT).o main.o

$(PROJECT).o: $(PROJECT).cpp $(PROJECT).hpp
	g++ $(CFLAGS) -o $(PROJECT).o $(PROJECT).cpp

main.o: main.cpp $(PROJECT).hpp
	g++ $(CFLAGS) -o main.o main.cpp

clean:
	rm -r *.o