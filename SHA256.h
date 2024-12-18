#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdint> // For fixed-width integer types

class SHA256 {
private:
    static constexpr size_t block_size = 64;  // Block size in bytes
    static constexpr size_t hash_size = 32;   // SHA-256 hash size in bytes

    uint32_t state[8];         // Internal state: A, B, C, D, E, F, G, H
    uint64_t bit_count;        // Total number of bits processed
    uint8_t buffer[block_size]; // Input data buffer
    uint8_t digest[hash_size];  // Final hash output

    // Helper methods for processing
    void padMessage();                        // Pads the message to align with the block size
    void processBlock(const uint8_t* block);  // Processes a 512-bit block

public:
    SHA256();                                // Constructor to initialize internal state
    void update(const uint8_t* message, size_t length); // Updates the hash with new data
    void final();                            // Finalizes the hash computation
    std::string getHashHex() const;          // Returns the computed hash as a hexadecimal string
};

#endif // SHA256_H
