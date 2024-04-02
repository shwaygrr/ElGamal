#include "ElGamal/elgamal.h"

int main() {
    std::string message = "hey babe is me, how are you";

    std::string int_rep = textToInt(message);
    std::cout << int_rep << std::endl;

    std::string text_rep = intToText(int_rep);
    std::cout << text_rep;

    return 0;

}

