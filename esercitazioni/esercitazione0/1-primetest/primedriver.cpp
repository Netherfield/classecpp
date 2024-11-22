// this is the file containing the main function


#include "prime.hpp"
#include <iostream>


int main()
{
    int n;
    float p;
    std::cout << "Please provide an integer:" << std::endl;
    std::cin >> n;
    p = log(n) / (float)n;
    if (isPrime(n))
        std::cout << "Congratulations, your integer " << n << " is a prime number, the odds were about log(n) / n = " << p << std::endl;
    else
        std::cout << "Unlucky, " << n << " is not a prime, but you just had a " << p << " chance of getting it" << std::endl;
    return 0;
}


















