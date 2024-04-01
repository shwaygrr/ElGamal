#include "ElGamal/elgamal.h"

int main() {
    const bigint modulus("115792089237316195423570985008687907853269984665640564039457584007913129639747");

    // std::cout << a - 2000;
    // std::cout << modExp(12, 2, modulus);
    for(int i = 0; i < 10; i++)
        std::cout << randNumGen(256) << std::endl;
    return 0;
}

