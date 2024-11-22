// funzioni effettive per manipolare i primi
#include "prime.hpp"

bool isPrime(int n){
    unsigned root, i;

    if (n <= 1)
        return false;
    else{
        root = sqrt(n);
        for (i = 2; i <= root; i++){
            if (n % i == 0) return false;
        }
    }
    return true;
}






