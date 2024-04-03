# ElGamal Public-Key Encryption Implementation

## Overview
This project implements the ElGamal Public-Key Encryption scheme in C++ using the BigInt library for working with large integers. The program allows users to generate public and private keys, encrypt plaintext messages, and decrypt ciphertext messages.

## Implementation Details
- Language: C++11 or older
- [BigInt](https://github.com/rgroshanrg/bigint?tab=readme-ov-file)


## Files and Folders Included
- `BigInt`: Contains the BigInt header file
    - `bigint.h`: BigInt header file also containing inline implementations 
- `ElGamal`: Containts the ElGamal header file and implementation file
    - `elgamal.h`: Contains header for libraries included, functions, and public key variables
    - `elgamal.cpp`: Implementation file containing implementation of all ElGamal functions
- `main.cpp`: Main file implementating the console interface for encryting and decryting messages
  
## How to run with VSCode
1. Open the `main.cpp` directory.
2. Build and Run
3. If there is error linking the files
    1. Open the `tasks.json` file in your Visual Studio Code workspace (`.vscode` directory)
    2. Ensure that the `args` property within the `"tasks"` array looks like the following:
        ```json
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "main.cpp",               // Compile main.cpp
                "ElGamal/elgamal.cpp",    // Compile ElGamal/elgamal.cpp
                "-I",
                "BigInt",                 // Include BigInt folder
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
        ```
    3. Save the `tasks.json` file.
    4. Build and Run in `main.cpp`

## How to run with command line
1. Build: `g++ -o output.exe main.cpp ElGamal/elgamal.cpp -I BigInt -std=c++11`
2. Run: `./main.exe`

#### Interacting with the Program
- Follow the on-screen instructions provided by the program:
    - Encryption
      - Type 'E' to encrypt a message
      - Enter message for encrytion
      - Enter desire key size(must be larger than message)
        -  [!WARNING] encryption will take longer with large messages and key size
      - You be provided with the public key, secret private key, and cipher text γ and δ 
    - Decryption (must first encrypt a message while program is running to decrypt)
      - Provide γ and δ and private key
      - You will be provided the original message.
  
![image](https://github.com/shwaygrr/elgamal/assets/122495108/3623f42f-978d-48d8-adc1-f2b23a62c20a)
