scriviamo un makefile generico, non e' specifico per il cpp e la sintassi e' fragile:

"cosa crea": "da cosa dipende"
    "che comando usa"

dateManager.exe: dataManager.o dateDriver.o
    g++ -o dateManager.exe dataManager.o dateDriver.o

dateManager.o: dateManager.cpp dateManager.hpp
    g++ -o -Wall -Wfatal-errors dateManager.cpp

dateDriver.o: dateDriver.cpp dateDriver.hpp
    g++ -o -Wall -Wfatal-errors dateDriver.cpp

clean:
    rm -f dataManager.o dataDriver.o dataManager.exe

i primi 3 comandi vengono eseguiti scrivendo a terminale:
    make
il comando "clean" viene eseguito solo con l'istruzione
    make clean

