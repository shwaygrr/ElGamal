#include "elgamal.h"

bigint modExp(bigint base, bigint exp, bigint modulus) {
    bigint result = 1;

    if (exp == 0) return result;

    bigint A = base;
    
    if (exp % 2 == 1) {
        result = base;
    }

    exp /= 2;

    while (exp != 0) {
        A = (A*A) % modulus;
        
        if (exp % static_cast<int>(2) == 1) result = (A*result) % modulus;

        exp /= 2; //next bit
    }

    return result;
}

