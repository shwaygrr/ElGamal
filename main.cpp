#include "ElGamal/elgamal.h"

int main() {
    const bigint modulus("115792089237316195423570985008687907853269984665640564039457584007913129639747");


    bigint gen = randGenerator(7);
    std::cout << gen << " is a generator" << std::endl;

    for(int i = 1; i < 7; i++) {
        std::cout << gen << "^" << i << " mod " << 7 << " = " << modExp(gen, i, 7) << std::endl;
    }
    return 0;

}

