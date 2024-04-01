#include "elgamal.h"

bigint modExp(const bigint& base, bigint exp, const bigint& modulus) {
    bigint result = 1;

    if (exp == 0) return result;

    bigint A = base;
    
    if (exp % 2 == 1) {
        result = base;
    }

    exp /= 2;

    while (exp != 0) {
        A = (A*A) % modulus;
        
        if (exp % 2 == 1) result = (A*result) % modulus;

        exp /= 2; //next bit
    }

    return result;
}


/*************************************************************************************Key Generation********************************************************************************/
/*
    1. get random number of bit size n
        -ex size = 20 bits 
    2. test random number
    3. do 1 and 2 until number is prime



*/

/*
    Binary to Decimal
        - Input: binary string
        - Output: large bigint
        https://www.geeksforgeeks.org/program-binary-decimal-conversion/
*/
bigint binaryToDecimal(std::string n) {
    std::string num = n;
    bigint dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    bigint base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

/*
    Random Number Generator
        - input: bit size
        - output: random number of bit size
        https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
*/
bigint randNumGen(unsigned int size){

	std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    
    std::uniform_int_distribution<unsigned short int> distrib(0,1);

    // return distrib(gen);
    std::string binary_str = "1";
 
    // Iterate over the range [0, N - 1]
    for (int i = 0; i < size-2; i++) {
        binary_str += std::to_string(distrib(gen));
    }

    binary_str += "1"; //ensure odd (prime)
	
    std::cout << binaryToDecimal(binary_str).as_str().length() << std::endl;
    return binaryToDecimal(binary_str); //converted to int
}

//get primitive root of p **allows every number between 1 and p to have equal chance of appearing**

//random number between 1 and p **private key**

