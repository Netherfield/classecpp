

#include <iostream>


#ifndef ACC_HPP
#define ACC_HPP
class ContoCorrente
{
    // il cpp permette solo di definire nella classe const di int e enum, e quindi vanno inizializzati nel source.cpp
    // in cpp moderno si puo' usare constexpr come segue
    static constexpr double cento_lire_euro = 19.3627;

    // gestisce il saldo come un numero unsigned di centesimi, conversione in lire e applicazioni di tassi sono uguali a meno di un fattore 1/100
    public:
        //metodi e costruttori
        ContoCorrente(){ saldo = 0; tasso = 0.0; };
        ContoCorrente(double t){ saldo = 0; tasso = t; };

        //selettori
        double TassoInteresse() const{ return tasso; }
        unsigned SaldoInEuro() const{ return saldo / 100; }
        unsigned SaldoCentesimi() const{ return saldo % 100; }

        double SaldoInLire() const;
        //funzioni di modifica
        void FissaTassoInteresse(double t){ tasso = t; }
        void DepositaEuro(unsigned unità, unsigned centesimi);
        void PrelevaEuro(unsigned unità, unsigned centesimi);
        void AggiornaSaldo();

    private:
        // metodi interni
        unsigned Centesimi(unsigned u, unsigned c) const;
        // variabili interne
        unsigned saldo;
        double tasso;
};

#endif














