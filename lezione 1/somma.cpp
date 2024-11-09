
// Programma 1 - Lezione 1, analisi e progettazione del software
// Questo programma stampa la somma dei primi 10 input da tastiera

#include <iostream>

// non ho voglia di usare il namespace per propedeutica, ma il comando sarebbe 'using'
// using namespace std

// definiamo una costante globale (non variabile)
// usiamo const invece di define perche' il define e' sintattico e causa problemi, esempio
// NUMERI = 10 + 8
// A = 5 * NUMERI
// ritorna A = 58 anzi che 5 * 18, perche' parte prima la moltiplicazione in 5 * 10 + 8
const unsigned NUMERI = 3;

int main()
{
    int numero, somma = 0;
    unsigned i;

    // frecce verso cout per ridirezionare l'output
    std::cout << "Inserisci " << NUMERI << " interi/n";
    for (i = 0; i < NUMERI; i++)
    {
        std::cout << "Inserisci il " << i+1 << "o numero:\n";
        // frecce verso la variabile quando cin ridireziona l'input verso la variabile
        std::cin >> numero; // poiche' numero e' un int, cin si aspetta solo un numero naturale, altri simboli o blank mandano in errore e vengono assorbiti nel prossimo cin
        somma += numero;
    }
    // per terminare un input andiamo a capo, ma nel c++ esiste una variabile endl che si occupa di quello
    // std::cout << "La somma totale e': " << somma << "\n";
    std::cout << "La somma totale e': " << somma << std::endl;

    int trash;
    std::cin >> trash;
    std::cout << trash;

    // Compiliamo dando il comando: (-Wall, "W" "all", tutti i warning)
    //
    // g++ -Wall -Wfatal-errors -o bin src.cpp
    //
    // l'opzione -Wfatal-errors ferma la compilazione appena trova un errore che non permette la compilazione del codice
    // esiste anche l'opzione -Wextra che usata insieme a -Wall mostra proprio tutti gli errori

    // exit(EXIT_SUCCESS);
    return 0;
}


