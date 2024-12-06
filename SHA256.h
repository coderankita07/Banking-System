#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class SHA256 {
private:
    static const size_t block_size = 64;  // Block size in bytes
    static const size_t hash_size = 32;   // SHA-256 hash size in bytes

    uint32_t state[8];       // Internal state (A, B, C, D, E, F, G, H)
    uint32_t count[2];       // Number of bits processed
    uint8_t buffer[block_size];  // Buffer for input data
    uint8_t digest[hash_size];   // Final hash output

    // Padding and length processing
    void padMessage(const uint8_t* message, size_t length);
    void processBlock(const uint8_t* block);

public:
    SHA256();
    void update(const uint8_t* message, size_t length);
    void final();
    string getHashHex() const;
};

#endif
