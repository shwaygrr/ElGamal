#ifndef ELGAMAL_H
#define ELGAMAL_H

#include "../BigInt/bigint.h"
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>
#include <string>

    bigint modExp(const bigint& base, bigint exp, const bigint& modulus);
    bigint randNumGen(unsigned int size);
#endif