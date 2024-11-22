


#ifndef VETT_HPP
#define VETT_HPP

#include <iostream>

class Vettore3D
{
    //funzioni di IO
    friend std::ostream& operator<<(std::ostream&, const Vettore3D&);
    friend std::istream& operator>>(std::istream&, Vettore3D&);

    // scalare v1 * v2
    friend double operator*(const Vettore3D&, const Vettore3D&);
    friend Vettore3D operator*(const Vettore3D&, double); // il prodotto per una costante
    friend Vettore3D operator*(double, const Vettore3D&);

    // operazioni sui vettori
    // solo + double e' const perche' non posso dichiarare const le funzioni esterne come + sui vettori
    // !!! in realta' non serve perche' la conversione da double a vet ce l'ho
    // dichiaro + come friend perche' voglio sia commutativa
    // friend Vettore3D operator+(const Vettore3D&, double); // non Vettore3D& perche' non modifico nulla e non posso passare il ref di una variabile locale
    // friend Vettore3D operator+(double, const Vettore3D&);
    friend Vettore3D operator+(const Vettore3D&, const Vettore3D&); // dichiaro friend esterna per evitare problemi di asimmetria nella conversione

    // prodotti
    // vettoriale v1 x v2
    friend Vettore3D operator&(const Vettore3D&, const Vettore3D&); // vale solo per i vettori

    public:
    // constructors and destructor
    Vettore3D(double init = 0.0) { x = y = z = init; } // inizializza al valore init
    Vettore3D(double a, double b, double c = 0.0) { x = a; y = b; z = c; }
    // ~Vettore3D();

    // selectors
    double x_coord() const { return x; }
    double y_coord() const { return y; }
    double z_coord() const { return z; }

    //accesso array like
    double operator[](int ind){ return (const double[]){x, y, z}[ind]; }

    // incrementatori
    Vettore3D& operator+=(const Vettore3D&); //modifico il vettore e restituisco il suo riferimento
    Vettore3D& operator+=(double); // stessa cosa ma per una costante double
    Vettore3D& operator&=(const Vettore3D&);
    Vettore3D& operator*=(double); // *= Vettore3D bon avrebbe senso, sarebbe un vettore di componenti prodotto

    private:
    double x, y, z; //apparently cpp doesn't allow for methods and variables sharing a name :'(

};


#endif






