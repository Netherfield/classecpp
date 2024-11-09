#include "yesterdate.hpp"



int main(){
    unsigned y, m, d;

    std::cout << "input y m d" << std::endl;
    std::cin >> y >> m >> d;
    std::cout << y << m << d << "\n";
    prevDate(y, m, d);
    std::cout << y << m << d << "\n";

    return 0;
}





