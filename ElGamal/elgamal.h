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
    bigint randOddNumGen(unsigned int size); //generate random large integer
    bigint randNumGen(const int min, const bigint& max) ;
    bool fermatsPrimeTest(const bigint& odd_int, unsigned int t); //test if integer is prime
    std::set<bigint> primeFact(bigint num);
    bigint randGenerator(const bigint& prime);
    void keyGen(bigint& prime, bigint& alpha, bigint& alpha_exp_priv);
    void encryption(const bigint& message);
    void decryption(bigint gamma, bigint delta, bigint priv_key, bigint prime, bigint alpha);
    bigint toInt(const std::string& message );
    bigint randPrimeGen(unsigned int size);
    std::string textToInt(const std::string& text);
    std::string intToText(const std::string& integer);
#endif