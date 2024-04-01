#include "ElGamal/elgamal.h"

int main() {
    const bigint modulus("115792089237316195423570985008687907853269984665640564039457584007913129639747");

    // std::cout << a - 2000;
    // std::cout << modExp(12, 2, modulus);
    for(int i = 1; i < 5; i++) 
    //     bigint num = randNumGen(3);
    //     std::cout << num << " - " << num._big_isPrime << std::endl;
    // }
    std::cout << randPrimeGen(3) << std::endl;; 
    return 0;
}

