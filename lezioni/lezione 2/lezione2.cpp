// Lezione 2
#include <lezione2.hpp>

#include <iostream>


// il canale cerr si comporta similmente a cout
// ma viene utilizzato per reindirizzare gli errori all'output gestito dalla console errori.
// ad esempio succede che cout rimanga in buffer per ottimizzazione, cerr invece viene flushato subito
void cerr(void){
    int a;
    std::cout << "please pick any number" << std::endl;
    std::cin >> a;
    std::cerr << "noo, not " << a << std::endl;
    return;
}

void ScopeStatico(void){
    
    {
        int x;
    }
    // throws undefined error
    // x = 3;

    int a;
    // non posso ridichiarare una variabile a nello stesso scope
    // double a;
    a = 10;
    {
        // pero' posso ridichiararla in uno scope diverso
        // anche se e' sconsigliato
        double a;
        a = 3.10;
    }
    std::cout << "la variabile a vale " << a << std::endl;
    //questo return non serve
    return;
}

void tipoBool(void){
    // la variabile booleana:
    bool b;
    b = true;
    // pero' gli operatori logici continuano a restituire tipi interi come il c, ovvero 0 e 1
    int a = 10;
    if (a > 5){
        // questo e' vero e ritorna 1, ma non true, infatti
        int c = (a > 5) + 1; //ritorna 2, perche' (a > 5) e' un int
        // std::cout << "c e' int e vale 2" << std::endl;
    }
}

bool verificaData (unsigned year, unsigned month, unsigned day){
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (year >= 1 && month >= 1 && month <= 12 && day >= 1 && days[month-1] >= day ) ||
    ( ((year % 400 == 0) || (year % 4 == 0 & year % 100 != 0)) && month == 2 && day == 29);
}

bool dataHandler(void){
    unsigned year, month, day;
    std::cout << "inserire anno mese e giorno please: " << std::endl;
    std::cin >> year >> month >> day;
    return verificaData(year, month, day);
}

void nextDate(unsigned& year, unsigned& month, unsigned& day){
    if (verificaData(year, month, day + 1))
        day++;
    else{
        day = 1;
        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
            month++; 
    }
}

// qua la F la stiamo solo dichiarando perche' la definizione l'abbiamo messa dopo il main
// la dichiarazione avviene anche durante la definizione e si puo' fare insieme
// tuttavia questo e' un modo molto snello di assegnare tutti i simboli delle funzioni e i loro parametri
// senza dovesi preoccupare dell'ordine delle definizioni
void F(int& a);

int main(){

    // cerr();
    // ScopeStatico();
    // tipoBool();
    // if (dataHandler()) std::cout << "data ok" << std::endl;

    //quiz
    // int b = 8;
    // F(b);
    // std::cout << "b = " << b << std::endl;
    unsigned year = 2025, month = 2, day = 28;
    std::cout << year << month << day << std::endl;
    nextDate(year, month, day);

    std::cout << year << month << day << std::endl;

    return 0;
}

// passaggio dei parametri per riferimento
//type& var, per F(b) assegna alla variabile var di tipo type il riferimento di b
//questo diventa utile per efficenza
void F(int& a)
{
    a = a + 5;
}
















