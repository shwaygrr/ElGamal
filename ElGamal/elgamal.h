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
#include <set>
#include <algorithm>
#include <tuple>
#include <sstream>
    //helper functions
    bigint modExp(const bigint& base, bigint exp, const bigint& modulus);
    bigint binaryToDecimal(const std::string& binary_str);

    //key generation functions
    bigint randOddNumGen(unsigned int size); //generate random large integer
    bigint randNumGen(const int min, const bigint& max) ;
    bool fermatsPrimeTest(const bigint& odd_int, unsigned int t); //test if integer is prime
    std::set<bigint> primeFact(bigint num);
    bigint randGenerator(const bigint& prime);
    void keyGen(const bigint& message);

    //encrytion/decryption
    void encryption(const bigint& message);
    std::string decryption(const bigint& gamma, const bigint& delta);
    bigint randPrimeGen(unsigned int size);

    //convertesion fucntions
    std::string textToInt(const std::string& text);
    std::string intToText(const std::string& integer);


    extern bigint prime;
    extern bigint alpha;
    extern bigint alpha_exp_priv;
#endif