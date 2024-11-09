
#include "ContoCorrente.hpp"


int main(){
    char ch;
    // creo un conto con tasso e uno senza
    ContoCorrente c1;
    ContoCorrente c2(0.03928); // il tasso e' tra 0 e 1, non 0 e 100

    //deposito in entrambi 20 euro e 100 cent
    c1.DepositaEuro(20, 100);
    c2.DepositaEuro(20, 100);

    //stampo i saldi
    std::cout << c1.SaldoInEuro() << " " << c1.SaldoCentesimi() << " " << c1.SaldoInLire() << " " << c1.TassoInteresse() << std::endl;
    std::cout << c2.SaldoInEuro() << " " << c2.SaldoCentesimi() << " " << c2.SaldoInLire() << " " << c2.TassoInteresse() << "\ny e invio per continuare" << std::endl;
    std::cin >> ch;
    //aggiorno i saldi
    c1.AggiornaSaldo();
    c2.AggiornaSaldo();

    //stampo i saldi
    std::cout << c1.SaldoInEuro() << " " << c1.SaldoCentesimi() << " " << c1.SaldoInLire() << " " << c1.TassoInteresse() << std::endl;
    std::cout << c2.SaldoInEuro() << " " << c2.SaldoCentesimi() << " " << c2.SaldoInLire() << " " << c2.TassoInteresse() << "\ny e invio per continuare" << std::endl;
    std::cin >> ch;

    //prelevo 2 euro in c1 e 20 cent in c2 e metto a c1 un tasso di 5.1
    c1.PrelevaEuro(2, 0);
    c2.PrelevaEuro(0, 20);

    c1.FissaTassoInteresse(0.051);

    //e aggiorno
    c1.AggiornaSaldo();
    c2.AggiornaSaldo();

    //stampo i saldi
    std::cout << c1.SaldoInEuro() << " " << c1.SaldoCentesimi() << " " << c1.SaldoInLire() << " " << c1.TassoInteresse() << std::endl;
    std::cout << c2.SaldoInEuro() << " " << c2.SaldoCentesimi() << " " << c2.SaldoInLire() << " " << c2.TassoInteresse() << "\ny e invio per continuare" << std::endl;
    std::cin >> ch;

    //test vari
    ContoCorrente c3 = c1;
    c3.PrelevaEuro(20, 100); // overflow
    c1.DepositaEuro(10000, 23184234);
    c2.DepositaEuro(203030, 1);

    //stampo
    std::cout << "c3: " << c3.SaldoInEuro() << " " << c3.SaldoCentesimi() << " " << c3.SaldoInLire() << " " << c3.TassoInteresse() << std::endl;
    std::cout << c1.SaldoInEuro() << " " << c1.SaldoCentesimi() << " " << c1.SaldoInLire() << " " << c1.TassoInteresse() << std::endl;
    std::cout << c2.SaldoInEuro() << " " << c2.SaldoCentesimi() << " " << c2.SaldoInLire() << " " << c2.TassoInteresse() << "\ny e invio per continuare" << std::endl;
    std::cin >> ch;

    return 0;
}















