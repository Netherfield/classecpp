/* Copyright 2024 Jacopo Barberis, Netherfield @ github
Software for education purposes, not intended for distribution
*/

#include "Poli.hpp"
#include <cmath>

// vettori permessi
// <7.1109x^5 + 4^x + 2.3> e <29x^9 + -4.3x^2 + 3x^1 + x^0> e <x^5 + 234.0>
std::ostream& operator<<(std::ostream& os, const Poli& p){
    // stampa i coefficienti solo se sono diversi da 1
    // stampa l'esponente solo se maggiore di 1
    // stampa la x solo se maggiore di 0
    // stampa il piu' solo se il coeff e' positivo
    int i = p.dim - 2;
    std::cout << '<' << p.pol[i + 1];
    while(i >= 0){
        (p.pol[i] >= 0) ? (std::cout << " +") : (std::cout << " ");
        std::cout << p.pol[i];
        i--;
    }
    std::cout << '>';
    return os;
}

std::ostream& operator<<(std::ostream& os, const Mono& m){
    if(m.e == 0)
        std::cout << m.c;
    else{
        if(m.c != 1)
            std::cout << m.c;
        if(m.e > 0)
            std::cout << 'x';
        if(m.e > 1)
            std::cout << '^' << m.e;
    }
    return os;
}



// <7.1109x^5 + 4x + 2.3> e <29x^9 + -4.3x^2 + 3x^1 + x^0> e <x^5 + 234.0>
std::istream& operator>>(std::istream& is, Poli& p){
    // legge il coefficiente sia col + e poi -
    // se non trova ^ dopo la x, segna 1
    // se non trova x prima di un segno +, - o > mette exp 0
    // se trova > e ha ancora caratteri nel buffer lo mette come ultimo coeff. e ha per forza exp = 0
    
    //resettiamo p
    delete[] p.pol;
    p.deg = 0;
    p.dim = 1;
    p.pol = new Mono[p.dim];
    p.pol[0] = Mono();
    
    char ch;
    std::string mon;
    std::cin >> ch >> ch;
    do {
        if(ch == '-' && !mon.empty()){
            std::cout << p;
            p += Mono(mon);
            mon.clear();
            mon += ch;
            std::cin >> ch;
        }
        if(ch == '+'){
            std::cout << p;
            p += Mono(mon);
            std::cout << p;
            mon.clear();
            std::cin >> ch;
        }
        mon += ch;
        std::cin >> ch;
    } while(ch != '>');
    if (!mon.empty()){
        std::cout << p;
        p += Mono(mon);
        std::cout << "forgot this case" << mon << std::endl;
        mon.clear();
    }
    std::cout << p;

    return is;
}

Mono::Mono(std::string s){
    //84.32x^4 oppure 95x oppure 493 oppure x^29 oppure x oppure 0 oppure 1
    int i = 0;
    int len = static_cast<int>(s.size());
    while(i < len){
        if(s[i] == 'x'){
            if(i != 0)
                c = std::stod(s.substr(0, i));
            else
                c = 1.0;
            if((len > i + 2)){ //2734x^4
                i += 2;
                e = std::stoi(s.substr(i, len - i));
            }
            else
                e = 1;
            i = len;
        }
        i++;
    }
    if (i == len){
        c = std::stod(s);
        e = 0;
    }
}

//con questo non serve definire > == ecc per i monomi
//il return type e' implicito quindi assumo che sia Mono::operator ... ??
Mono::operator double() const{
    return c;
}

Poli::Poli(double c, int e){
    deg = e;
    dim = 1;
    pol = new Mono[1];
    pol[0] = Mono(c, e);
}

Poli::Poli(const Poli& p){
    deg = p.deg;
    // delete[] pol; // non serve non ha nulla legato e' nuovo
    pol = new Mono[p.dim];
    for(dim = 0; dim < p.dim; dim++) pol[dim] = p.pol[dim];
}

Poli::~Poli(){ delete[] pol; }

Poli& Poli::operator=(const Poli& p){
    deg = p.deg;
    delete[] pol;
    pol = new Mono[p.dim];
    for(dim = 0; dim < p.dim; dim++) pol[dim] = p.pol[dim];

    return *this;
}

double Poli::operator()(double x){
    double eval = 0;
    for(int i = 0; i < dim; i++){
        eval += pol[i](x);
    }
    return eval;
}

double Mono::operator()(double x){
    double ret;
    if(e == 0)
        ret = x;
    if(e == 1)
        ret = c*x;
    else
        ret = c * std::pow(x, e);

    return ret;
}

double Poli::operator[](int e){
    if(e > deg) return 0.0;
    else{
        for(int i = 0; i < dim; i++){
            if (pol[i].e == e) return pol[i].c;
        }
    }
    return 0.0;
}


Poli operator+(const Poli& p1, const Poli& p2){
    // sommare con un merge
    // non dimenticare di eliminare coefficienti nulli con esponente > 0
    Poli r = p1;
    for(int i = 0; i < p2.dim; i++){
        r += p2.pol[i]; // aggiungo un monomio alla volta
    }
    return r;
}

Poli operator-(const Poli& p1, const Poli& p2){
    return p1 + p2.inverse();
}

//override del simbolo meno unario
Mono Mono::operator-(){
    Mono m(-c, e);
    return m;
}

Poli& Poli::operator+=(const Mono m){
    // prima sommo
    // se c'e' gia' l'indice sommo dove c'e' altrimenti inserisco
    int ind = find(m.e);
    if(ind != -1)
        pol[ind].c += m.c;
    else
        insert(m);
    // poi trimmo
    // tolgo tutti i termini 0 rimasti tranne se e' solo rimasto 0x^0
    trim();

    return *this;
}

Poli operator*(const Poli& p1, const Poli& p2){
    Poli r;
    for(int i = 0; i < p1.dim; i++){
        for(int j = 0; j < p2.dim; j++){
            r += p1.pol[i] * p2.pol[j];
        }
    }
    return r;
}

Mono operator*(const Mono& m1, const Mono& m2){
    return Mono(m1.c * m2.c, m1.e + m2.e);
}

Poli Poli::inverse() const{
    Poli r = *this;
    for(int i = 0; i < dim; i++){
        r.pol[i] = -pol[i];
    }
    return r;
}

int Poli::find(int e) const{
    int ind = dim;
    while(pol[ind].e != e && ind > -1) ind--;
    return ind;
}

Poli& Poli::insert(const Mono m){
    Mono* aux = new Mono[dim + 1];
    int i;
    if (deg < m.e) {
        for(i = 0; i < dim; i++) aux[i] = pol[i];
        aux[i] = m;
        deg = m.e;
    }
    else{
        //alla fine del ciclo i e' la nuova posizione di e
        i = 0;
        while(pol[i].e < m.e){
            aux[i] = pol[i];
            i++;
        }
        aux[i] = m;
        while(i < dim){
            aux[i + 1] = pol[i];
            i++;
        }
    }
    delete[] pol;
    pol = aux;
    dim++;

    return *this;
}

Poli& Poli::remove(const int ind){
    Mono* aux = new Mono[dim-1];
    int i;
    for(i = 0; i < ind; i++) aux[i] = pol[i];
    for(;i < dim; i++) aux[i - 1] = pol[i];
    delete[] pol;
    pol = aux;
    dim--;
    deg = pol[dim - 1].e;

    return *this;
}

Poli& Poli::append(const Mono m){
    if(dim == 1 && pol[0] == 0){
        pol[0] = m;
        return *this;
    }
    else
        return insert(m);
}

Poli& Poli::trim(){
    Poli r;
    // se il polinomio ha coeff != 0 lo aggiunge ad r
    // per evitare ricorsione infinita bisogna avere un else che termina
    // se lo faccio per ogni polinomio di grado 1 ad esempio, non finiro' mai
    // devo ridurre di 1 grado per iterazione
    for(int i = 0; i < dim; i++){
        if(pol[i] != 0)
            r.append(pol[i]);
    }
    *this = r;
    return *this;
}











