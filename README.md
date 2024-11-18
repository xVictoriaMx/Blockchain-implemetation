# **Blockchain Project**

## **Project Objective**

The objective of this project is to create a simple blockchain implementation in C++ that mimics the core functionality of a cryptocurrency blockchain. This includes creating a ledger of blocks, supporting transactions, and implementing mining functionality using the SHA-256 hash algorithm.

## **Overview**
This project implements a basic blockchain with transaction handling and mining features. The blockchain is built using C++ and the SHA-256 hashing algorithm for block validation. It simulates transactions within blocks and requires computational work (proof-of-work) to mine new blocks.

## **Key Features:**
- **Blockchain:** A linked list of blocks, each containing a set of transactions.
- **Transactions:** Support for adding transactions to a block.
- **Mining:** The ability to mine new blocks by solving a proof-of-work problem.
- **SHA-256:** Used to generate block hashes to ensure data integrity and security.

The project utilizes a custom SHA-256 hashing algorithm (implemented in pure C++) to secure transactions and links blocks together, mimicking the fundamental operation of popular blockchains like Bitcoin.

## **Getting Started**

**Dependencies:**
- Operating System: Windows 10, Linux, or macOS
- C++ Compiler: GCC 4.8 or later (supports C++11 or C++17)
- Libraries: No external libraries are required, as the SHA-256 hashing is implemented in pure C++.

## **Core Logic and Functions**

### **Blockchain Structure**
The blockchain consists of a series of blocks that are chained together using the previous hash stored in each block. Each block contains:

- **Index:** The position of the block in the chain.
- **Timestamp:** The creation time of the block.
- **Transactions:** A list of transactions included in the block.
- **Previous Hash:** The hash of the previous block.
- **Hash:** The SHA-256 hash of the current block.

### **Transactions**
Transactions are the core component of the blockchain. Each transaction consists of:

- **Sender:** The account from which funds are being sent.
- **Receiver:** The account receiving the funds.
- **Amount:** The amount of funds being transferred.
Transactions are added to the current block until the block reaches a predefined size or until mining begins.

### **Mining**
Mining involves finding a valid *nonce* (a number) that, when hashed with the rest of the block’s contents, produces a hash that starts with a specific number of leading zeros. This process simulates the computational work required for the proof-of-work in cryptocurrencies.

The mining process is handled by the `mineBlock` function, which continuously hashes the block’s contents until the required number of leading zeros is found.

### **SHA-256 Hashing**
SHA-256 is used to create a unique hash for each block. This ensures that each block’s content is tamper-proof, as even the smallest change in data will result in a completely different hash.

The `sha256` function is used to hash the block’s contents, including the index, timestamp, transactions, and previous block’s hash.

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
