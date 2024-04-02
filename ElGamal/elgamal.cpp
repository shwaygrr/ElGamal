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
bigint binaryToDecimal(const std::string& binary_str) {
    bigint dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    bigint base = 1;
 
    int len = binary_str.length();
    for (int i = len - 1; i >= 0; i--) {
        if (binary_str[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}


/*
    Random Number Generator
        - input: bit size, size 
        - output: random odd number of bit size, size
        https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
*/
bigint randOddNumGen(unsigned int size){

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
	
    // std::cout << binaryToDecimal(binary_str).as_str().length() << std::endl;
    return binaryToDecimal(binary_str); //converted to int
}


/*
    Random Number Generator
        - input: min and max 
        - output: random number between min and max inclusive
        https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
*/
bigint randNumGen(const int min, const bigint& max) {
    //error handling
    if (min >= max) {
        throw std::invalid_argument("min must be less than max");
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    //number of bits required to represent max
    std::string max_bit_size = (big_log2(max)+1).as_str();

    //generate a random number within range
    bigint rand_num;

    do {
        std::string binary_str;
        for (int i = 0; i < std::stoi(max_bit_size); i++) {
            binary_str += std::to_string(gen() % 2);
        }
        rand_num = binaryToDecimal(binary_str);
    } while (rand_num < min || rand_num > max);

    return rand_num;
}



/*
    Fermats Primality Test
        - Input: odd integer, n >= 3 (must be at least 4 bits), and security parameter, t >=1
        - Output: isPrime
*/
bool fermatsPrimeTest(const bigint& odd_num, unsigned int t) {
    for(int i = 0; i < t; i++) {
        bigint ran_num = randNumGen(2, odd_num-2);
        bigint r = modExp(ran_num, odd_num-1, odd_num);
        if (r != 1) return false;
    }
    return true;
}


/*
    Large Prime Generator
        -Input: bit size, n
        -Output: prime number of bitsize n tested by fermat
*/
bigint randPrimeGen(unsigned int size) {
    bigint rand_num;
    
    do {
        rand_num = randOddNumGen(size);
    } while(fermatsPrimeTest(rand_num, 50) == false );
    
    return rand_num;
}


/*
    Prime Factorization
        input: interger
        Output: prime factorizaton
*/
std::set<bigint> primeFact(bigint num) {
    std::set<bigint> factors;

    //reduce until odd
    while (num % 2 == 0) {
        factors.insert(2);
        num = num / 2; 
    }
 
    //check numbers from 3 to sqrt(num) skipping even numbers
    for (int i = 3; i <= big_sqrt(num); i += 2) { 
        while (num % i == 0) { 
            factors.insert(i); 
            num = num / i; 
        } 
    } 
    
    //if num is a prime greater than 2
    if (num > 2) factors.insert(num);

    return factors;
}

/*
    Random generator (primitive root)
        -Input: prime number
        -Output: random primitive root
*/
bigint randGenerator(const bigint& prime) {
    std::set<bigint> prime_factors = primeFact(prime-1);

    bigint alpha;
    bigint b;

    do {
        alpha = randNumGen(2, prime - 1);

        for (const bigint& prime_factor : prime_factors) {
            b = modExp(alpha, (prime-1)/prime_factor, prime);
            if (b == 1) break;
        }
    } while (b == 1);

    return alpha;
}

/*
    Key Generation
        -Input: -
        -Output: 
*/
void keyGen(bigint& prime, bigint& alpha, bigint& alpha_exp_priv) {
    
    //generate large prime
    unsigned int size;
    std::cout << "Choose bit size (must be larger than message): ";
    std::cin >> size;

    prime = randPrimeGen(size);

    //get generator
    alpha = randGenerator(prime);

    //calculate alpha^a mod p
    bigint priv_key = randNumGen(1, prime-2);
    
    std::cout << "The private key is: " << priv_key << std::endl;

    alpha_exp_priv = modExp(alpha, priv_key, prime);

    std::cout << "The public key is: " << std::endl
        << "\tp: " << prime << std::endl
        << "\tα: " << alpha << std::endl
        << "\tα^a: " << alpha << std::endl;       
}


/*
    Encryption
        Input: message as integer
        Output: ciphertext as integer
*/
void encryption(const bigint& message) {
    bigint prime, alpha, alpha_exp_priv; //make global

    //generate keys
    keyGen(prime, alpha, alpha_exp_priv);
    
    bigint k = randNumGen(1, prime-2);

    //gamma and delta
    bigint gamma = modExp(alpha, k, prime);
    bigint delta = message * modExp(alpha, alpha*k, prime);

    std::cout << "Ciphertext: " << std::endl
        <<"\tγ: " << gamma << std::endl
        << "\tδ: " << delta << std::endl;
}


/*
    Decryption
        Input: ciphertext as integer
        Output: message as integer
*/
void decryption(bigint gamma, bigint delta, bigint priv_key, bigint prime, bigint alpha) {
    bigint ciphertext  = modExp(gamma, prime-1-alpha, prime);
    std::cout << "Message: " << ciphertext;
}
//random number between 1 and p **private key**

//get primitive root of p **allows every number between 1 and p to have equal chance of appearing**


