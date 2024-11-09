


#include "newtonroot.hpp"



int main(){

    int n;
    double d, root, newt;
    

    std::cout << "Give a number to get the root: " << std::endl;
    std::cin >> d;

    if ( d < 0 ){
        std::cout << "complex numbers not found" << std::endl;
        return 0;
    }

    std::cout << "And up to which decimal position: (between 0 and 6 please)" << std::endl;
    std::cin >> n;

    root = sqrt(d);
    newt = newtonroot(d, n);

    std::cout << "The root up to " << n << " decimal position is: "  << truncate(root, n) << std::endl;
    std::cout << "Without truncation is: "  << root << std::endl;
    std::cout << "Same but through our own implementation: " << newt << std::endl;
    std::cout << "Without truncation is: "  << truncate(newt, n) << std::endl;


    return 0;
}







