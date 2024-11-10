


#include <iostream>

class Mono{
    public:
        friend std::ostream& operator<<(std::ostream& os, const Mono& m);
        
        // useless, let's overload the typecast to double!! how?? i don't know yet!
        // friend bool operator>=(const Mono&, const Mono&);
        // friend bool operator==(const Mono&, const Mono&);

        friend Mono operator*(const Mono&, const Mono&);

        Mono(double a = 0.0, int b = 0){ c = a; e = b;}
        Mono(std::string);

        // operator non e' il return type, e' implicito che sia double
        operator double() const;

        Mono operator-();
        double operator()(double);
        
        double c; // coefficiente
        int e; // esponente
    };


// Classe che definisce le operazioni su anelli polinomiali sul campo R
class Poli{
    // IO FUNCTIONS
    friend std::ostream& operator<<(std::ostream& os, const Poli& p);
    friend std::istream& operator>>(std::istream& is, Poli& p); // <7.1x^5 + 4.2x^3 + 1x^1 + -9.3x^0>


    // OVERLOADS
    friend Poli operator+(const Poli&, const Poli&);
    friend Poli operator-(const Poli&, const Poli&);

    friend Poli operator*(const Poli&, const Poli&);

    public:
    // costruttori
    Poli(double c = 0.0, int e = 0); // e = 0, per il polinomio costante e c = 0.0 per l'elemento neutro
    Poli(const Poli&); //costruttore di copia
    ~Poli(); // rilascia tutta la memoria
    
    // assegnazione
    Poli& operator=(const Poli&);
    // eval
    double operator()(double); // valuta il polinomio in double

    // selettori
    double operator[](int e); // restituisce il coeff all'esponente e

    // incrementatori
    Poli& operator+=(const Poli&);
    Poli& operator+=(const Mono);
    Poli& operator-=(const Poli&);

    private:
    Poli inverse() const;
    int find(int) const;
    Poli& insert(const Mono);
    Poli& remove(const int);
    Poli& _trim(); //restituisce il polinomio ridimensionato
    Poli& trim();
    Poli& append(const Mono);

    // variabili interne
    int deg;
    int dim;
    Mono* pol;

};





