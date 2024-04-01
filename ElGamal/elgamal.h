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

    //helper functions
    bigint modExp(const bigint& base, bigint exp, const bigint& modulus);
    bigint binaryToDecimal(const std::string& binary_str);
    bigint randNumGen(unsigned int size); //generate random large integer
    bigint randNumGen(bigint& max) ;
    bool fermatsPrimeTest(const bigint& odd_int, unsigned int t); //test if integer is prime
    
    bigint randPrimeGen(unsigned int size);
#endif