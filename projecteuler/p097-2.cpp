void solve_097(){
    auto start = std::chrono::high_resolution_clock::now();

    unsigned long long mod = intPow(10, 10);

    unsigned long long result = 28433 * intPowMod2(2, 7830457, mod) + 1;
    result %= mod;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "The last 10 digits are " << result << "." << std::endl;
    std::cout << "Computation took " << elapsed.count() << " microseconds." << std::endl;
}

unsigned long long intPowMod2(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    while (exp >= 2) {
        if (exp % 2) {
            result = multMod(result, base, mod);
        }
        base = multMod(base, base, mod);
        exp /= 2;
    }
    result = multMod(result, base, mod);
    return result;
}

//Multiplication for really really large integers whose product can't fit in unsigned long long
unsigned long long multMod(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long result = 0;
    a %= mod;
    b %= mod;
    while (b) {
        if (b % 2) {
            result += a;
            result %= mod;
        }
        a *= 2;
        a %= mod;
        b /= 2;
    }
    return result;
}