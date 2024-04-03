#include "ElGamal/elgamal.h"

int main() {
    char prompt;

    std::cout << "Welcome to the ElGamal Encryption algorithm! Encrypt or Decrypt your messages" << std::endl;


    do {
        std::cout << "Enter 'E' to encrypt or 'D' to decrypt (press any key to quit): ";
        std::cin >> prompt;
        std::cin.ignore();
        if (prompt == 'E') {
            //read message
            std::string message;
            std::cout << "Enter the message you would like to encrypt: ";
            std::getline(std::cin, message);

            //convert message
            bigint message_int = textToInt(message);
            //encrypt message
            encryption(message_int);
            prompt = 'h';
        } else if (prompt == 'D') {
            std::string gamma, delta;

            std::cout << "Enter γ: ";
            std::cin >> gamma;

            std::cout << "Enter δ: ";
            std::cin >> delta;

            std::string message = decryption(gamma, delta);
            std::cout << "Message Decrypted: " << intToText(message) << std::endl;
        }
    
    } while (prompt == 'E' || prompt == 'D');

    return 0;

}

