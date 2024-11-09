
#include "Vettori3D.hpp"

std::ostream& operator<<(std::ostream& os, const Vettore3D& v){
    // il vettore 0.0, ritorna come Vettore3D(0, 0, 0)
    std::cout << "Vettore3D(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vettore3D& v){
    // Vettore3D(4.329, 0, 1230)
    char ch;
    do{
        std::cin >> ch;
    } while (ch != '(');
    std::cin >> v.x >> ch >> v.y >> ch >> v.z >> ch;
    return is;
}

// v1 = v1 + 5 -> v1 = v1 + vett(5, 5, 5)
Vettore3D operator+(const Vettore3D& v1,const Vettore3D& v2){
    Vettore3D v(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    return v;
}

Vettore3D& Vettore3D::operator+=(const Vettore3D& v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

// Vettore3D operator+(const Vettore3D& v, double a){
//     Vettore3D w(v.x + a, v.y + a, v.z + a);
//     return w;
// }
// Vettore3D operator+(double a, const Vettore3D& v){ return v + a; } //commutativo

Vettore3D& Vettore3D::operator+=(double a){
    x += a;
    y += a;
    z += a;
    return *this;
}

Vettore3D operator&(const Vettore3D& v1, const Vettore3D& v2){
    Vettore3D w(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.z);
    return w;
}
Vettore3D& Vettore3D::operator&=(const Vettore3D& v){
    double a = x, b = y;
    x = y * v.z - z * v.y;
    y = z * v.x - a * v.z;
    z = a * v.y - b * v.x;
    return *this;
}


double operator*(const Vettore3D& v1, const Vettore3D& v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// ATTENZIONE, questo serve perche' se lasciassi fare il cast da double a vett3D allora userebbe il prodotto scalare, che restituisce double e non Vett3D, questo e' il prodotto x uno scalare DIVERSO
Vettore3D operator*(const Vettore3D& v, double s){
    Vettore3D w(v.x * s, v.y * s, v.z * s);
    return w;
}
Vettore3D operator*(double s, const Vettore3D& v){ return v + s; } //commutativo

Vettore3D& Vettore3D::operator*=(double s){
    x *= s;
    y *= s;
    z *= s;
    return *this; // this is just the syntax for returning something by reference in c++, you write object& function(){ return *object; }
}




