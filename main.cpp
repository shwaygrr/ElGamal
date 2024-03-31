#include "ElGamal/elgamal.h"

int main() {
    const bigint modulus("115792089237316195423570985008687907853269984665640564039457584007913129639747");

    // std::cout << a - 2000;
    std::cout << modExp(12, 2, modulus);

    return 0;
}