#include <ctime>
#include <iostream>

long power(const int FACTOR, const int NUMBER, const int EXPONENT) {
    long result = FACTOR * NUMBER;
    for(int i = 1; i < EXPONENT; ++i) {
        result *= NUMBER;
        result %= 10000000000;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    time_t start, finish;
    start = clock();
    
    std::cout << power(28433, 2, 7830457) + 1 << std::endl;
    
    finish = clock();
    std::cout << "Completed in " << float(finish - start) / CLOCKS_PER_SEC << " seconds.\n";
    
    return 0;
}