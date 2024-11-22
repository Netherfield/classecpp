
#include "IOpyramid.hpp"


int main(){
    int n;

    std::cout << "Please provide an integer n between 1 and 9" << std::endl;
    std::cin >> n;

    if((n < 10) && (n > 0)){
        std::cout << "Valid:\n" << std::endl;
        numPy(n); //which stands for num(ber)Py(ramid), not the python library    }
    }
    return 0;
}









