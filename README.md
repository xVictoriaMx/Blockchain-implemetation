## **Blockchain Project**

## **Project Objective**

This project is a simple blockchain implementation in C++ with features such as transactions, a ledger, and mining functionality. It is designed to demonstrate how a basic blockchain operates, with the ability to create blocks, validate transactions, and mine them through a proof-of-work algorithm.

## **Overview**
This C++ project implements a basic blockchain from scratch. It features the following components:

**Transactions:** A system to send and receive transactions between users.
**Ledger:** The blockchain serves as a ledger for storing transaction data.
**Mining:** A proof-of-work mining algorithm that requires computational effort to mine new blocks, ensuring the security and integrity of the blockchain.

The project utilizes a custom SHA-256 hashing algorithm (implemented in pure C++) to secure transactions and links blocks together, mimicking the fundamental operation of popular blockchains like Bitcoin.

## **Getting Started**

**Dependencies:**
- Operating System: Windows 10, Linux, or macOS
- C++ Compiler: GCC 4.8 or later (supports C++11 or C++17)
- Libraries: No external libraries are required, as the SHA-256 hashing is implemented in pure C++.


## **Installing**
1. Clone this repository:

```bash
git clone https://github.com/xVictoriaMx/blockchain-project.git
cd blockchain-project
```
2. Compile the Program: Ensure you have a C++ compiler installed (e.g., g++).

```bash
g++ -std=c++17 -o blockchain main.cpp
```
3. Run the Program: Execute the compiled program:

```bash
./blockchain
```

No further modifications are needed for the basic setup. The program will run a demo of transactions being added and mined into blocks.

## **Executing Program**

To run the program, follow these steps:

1. Clone the repository and navigate to the project directory.
2. Compile the project using the following command:
```bash
g++ -std=c++17 -o blockchain main.cpp)
```
4. Once compiled, run the program: 
```bash
./blockchain
```
You should see the blockchain being created and transactions being mined with output like this:
```cpp
yaml
Mining first block...
Block mined: <hash>
Blockchain:
Block 1 <hash>
Previous: <previous block hash>
Timestamp: <timestamp>
Transactions:
  - Alice -> Bob : 10
Nonce: <nonce>
```

## **License**

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

## **Authors and Acknowledgment**

Blockchain Implementation was created by **[Victoria M](https://github.com/xVictoriaMx)**.
