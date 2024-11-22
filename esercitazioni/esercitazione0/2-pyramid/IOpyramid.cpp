
#include "IOpyramid.hpp"



void numPy(int n){
    int line, pos;
    std::string coda;

    // each line, like this one -> 0000123210000
    // is determined by a position recursion
    // that's line 3, if there's a 3 it's always line 3,
    // the number of 0s tell us that there are 4 more lines so, n = 7
    // so, each place in that line can be determined knowing n and the line
    // the 0s are "n - line"
    // then it should count from 1 to line and back to 1
    // two implementations
    // 

    //symmetric loops
    std::cout << "We use two symmetric loops to populate the pyramid" << std::endl;
    for(line = 1; line < n + 1; line++){
        coda = std::string(n - line + 1, ' '); //does it work for length 0?
                                            std::cout << coda;
        for(pos = 1; pos < line; pos++)     std::cout << pos;
                                            std::cout << line;
        for(pos = line - 1; pos > 0; pos--) std::cout << pos;
                                            std::cout << "\n";
    }
    std::cout << std::endl;
}







