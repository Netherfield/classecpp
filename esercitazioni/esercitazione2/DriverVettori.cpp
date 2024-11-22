

#include "Vettori3D.hpp"

int main(){
    std::cout << "hi" << std::endl;
    // attenzione Vettore3D v1(); sarebbe letto come dichiarazione della funzione v1()!!!!
    Vettore3D v1;
    Vettore3D v2(2.0, 3.1, 5.442);

    std::cout << v1.x_coord() << v1.y_coord() << v1.z_coord() << std::endl;
    std::cout << v2.x_coord() << v2.y_coord() << v2.z_coord() << std::endl;
    std::cout << v1 << " " << v2 << std::endl;
    std::cout << v1 * v2 << " " << 5.6 * v1 << " " << (v1 & v2) << " " << std::endl;

    Vettore3D v3;
    v1 += 3.2;
    v3 = v1 + v2;
    
    Vettore3D v4(2.0);
    v1 += v4;
    v2 = v3;

    std::cout << v1.x_coord() << v1.y_coord() << v1.z_coord() << std::endl;
    std::cout << v2.x_coord() << v2.y_coord() << v2.z_coord() << std::endl;
    std::cout << v1 << " " << v2 << std::endl;

    v1 *= 10;
    v2 &= Vettore3D(4.19);
    std::cout << v1 << " " << v2 << std::endl;

    Vettore3D w;
    std::cout << w << " scrivere un vettore" << std::endl;

    std::cin >> w;
    std::cout << "vettore inserito \n" << w << " indice da 0 a 2 please: " << std::endl;
    
    int i;
    std::cin >> i;
    std::cout << "il vettore all'indice ha il valore: " << w[i] << std::endl;

    return 0;
}



























