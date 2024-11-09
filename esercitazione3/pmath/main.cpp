
#include "Poli.hpp"



int main(){
    Poli p(4.5, 2);
    Poli q(3.4, 4);
    Poli k;
    Poli j;
    Poli z;
    Poli l(23, 1);
    Poli c(3.412);
    Poli a = l + c;
    k = p + q;
    j = p - q;

    std::cout << k << p << q << std::endl;
    std::cout << z << l << c << std::endl;
    std::cout << a << std::endl;
    std::cout << j << std::endl;
    std::cout << k[20] << k[0] << k[2] << std::endl;
    std::cout << k(3.4) << std::endl;
    std::cout << a(23) << std::endl;
    std::cout << a(-0.0823) << std::endl;

    std::cout << "dammi un polinomio" << std::endl;
    std::cin >> k;

    std::cout << "mi hai dato:\n" << k << std::endl;
    std::cout << "dammi un polinomio" << std::endl;
    std::cin >> p;

    std::cout << "mi hai dato:\n" << p << std::endl;
    std::cout << "dammi un polinomio" << std::endl;
    std::cin >> q;

    std::cout << "mi hai dato:\n" << q << std::endl;
    return 0;
}



















