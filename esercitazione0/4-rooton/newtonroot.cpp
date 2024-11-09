#include "newtonroot.hpp"



double truncate(double d, unsigned n){
    return (static_cast<int>(d * pow(10, n))) / static_cast<double>(pow(10, n));
}


double newtonroot(double d, unsigned n, double iter){
    double next = (iter + (d / iter)) / 2.0;
    if (static_cast<int>((iter - next)*pow(10, n)) == 0 )
        return next;
    return newtonroot(d, n, next);
}




