#include "SHA256.h"
#include <cstring>
#include <iomanip>
#include <sstream>

// SHA-256 Constants
static const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xade682d1, 0x1d1c2e41, 0x1c1e4fa7, 0x4f46d7c3, 0x582e3e9a, 0x5a0ec0ed, 0x23a3d79f, 0x6122ff75,
    0x4e9e3d76, 0x5474f8c1, 0x10d99ed7, 0xd0d65a02, 0x42bc9a53, 0x9fdc9db4, 0x72a6d076, 0x7380fa91,
    0x8d04ecbb, 0x9db57b1f, 0x295f2c26, 0x34912139, 0x2f1f3b56, 0xa6b29a25, 0x7b6a4129, 0x3f1b3f64,
    0x2f30565e, 0x2672d5fe, 0xd76caa09, 0x7813a746, 0xd6f39a72, 0x1fe7a0e1, 0x924b9b84, 0x54c103aa,
    0xf0b7c585, 0x5fbfce0b, 0x7a8f3a70, 0x4a78f574, 0x79c02fd7, 0xf0b7369b, 0x0c8e2884, 0x38f63d80
};

// Initialize SHA256 state
SHA256::SHA256() {
    state[0] = 0x6a09e667;
    state[1] = 0xbb67ae85;
    state[2] = 0x3c6ef372;
    state[3] = 0xa54ff53a;
    state[4] = 0x510e527f;
    state[5] = 0x9b05688c;
    state[6] = 0x1f83d9ab;
    state[7] = 0x5be0cd19;

    count[0] = 0;
    count[1] = 0;
    memset(buffer, 0, block_size);
}

void SHA256::update(const uint8_t* message, size_t length) {
    size_t index = (count[0] / 8) % block_size;  // Index in the current block
    count[0] += length * 8;  // Update the bit count
    if (count[0] < length * 8) count[1]++;  // Check for overflow of bit count

    size_t i = 0;
    while (i < length) {
        buffer[index++] = message[i++];
        if (index == block_size) {
            processBlock(buffer);
            index = 0;
        }
    }
}

void SHA256::final() {
    uint8_t padding[block_size] = {0x80};  // 0x80 is the padding byte
    size_t paddingSize = block_size - (count[0] / 8) % block_size;
    if (paddingSize < 9) {
        paddingSize += block_size;  // If space for length is not enough, add extra block
    }

    update(padding, paddingSize - 8);  // Update with padding

    uint64_t bitLength = count[0];
    padding[0] = 0x80;
    padding[1] = (bitLength >> 56) & 0xFF;
    padding[2] = (bitLength >> 48) & 0xFF;
    padding[3] = (bitLength >> 40) & 0xFF;
    padding[4] = (bitLength >> 32) & 0xFF;
    padding[5] = (bitLength >> 24) & 0xFF;
    padding[6] = (bitLength >> 16) & 0xFF;
    padding[7] = (bitLength >> 8) & 0xFF;
    padding[8] = bitLength & 0xFF;

    update(padding, 8);  // Process length part of padding

    for (int i = 0; i < 8; ++i) {
        digest[i * 4] = (state[i] >> 24) & 0xFF;
        digest[i * 4 + 1] = (state[i] >> 16) & 0xFF;
        digest[i * 4 + 2] = (state[i] >> 8) & 0xFF;
        digest[i * 4 + 3] = state[i] & 0xFF;
    }
}

string SHA256::getHashHex() const{
    stringstream ss;
    for (int i = 0; i < hash_size; i++) {
        ss << setw(2) << setfill('0') << hex << (int)digest[i];
    }
    return ss.str();
}

// Process a 512-bit block (64 bytes)
void SHA256::processBlock(const uint8_t* block) {
    uint32_t w[64];
    for (int i = 0; i < 16; ++i) {
        w[i] = (block[i * 4] << 24) | (block[i * 4 + 1] << 16) | (block[i * 4 + 2] << 8) | block[i * 4 + 3];
    }

    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = (w[i - 15] >> 7) | (w[i - 15] << (32 - 7));
        uint32_t s1 = (w[i - 2] >> 17) | (w[i - 2] << (32 - 17));
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t e = state[4], f = state[5], g = state[6], h = state[7];

    for (int i = 0; i < 64; ++i) {
        uint32_t s1 = (e >> 6) | (e << (32 - 6));
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t temp1 = h + s1 + ch + k[i] + w[i];
        uint32_t s0 = (a >> 2) | (a << (32 - 2));
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = s0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}
