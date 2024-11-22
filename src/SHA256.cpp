#include "SHA256.h"
#include <sstream>
#include <iomanip>

using namespace std;

SHA256::SHA256() {
    reset();
}

void SHA256::update(const uint8_t* data, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        buffer[bufferLength++] = data[i];
        if (bufferLength == BlockSize) {
            processBlock();
            bitLength += BlockSize * 8;
            bufferLength = 0;
        }
    }
}

array<uint8_t, SHA256::HashSize> SHA256::finalize() {
    array<uint8_t, HashSize> hash;

    // Padding
    buffer[bufferLength++] = 0x80;
    if (bufferLength > 56) {
        while (bufferLength < BlockSize) buffer[bufferLength++] = 0x00;
        processBlock();
        bufferLength = 0;
    }
    while (bufferLength < 56) buffer[bufferLength++] = 0x00;

    // Append length
    for (int i = 7; i >= 0; --i)
        buffer[bufferLength++] = (bitLength >> (i * 8)) & 0xFF;
    processBlock();

    // Convert to hash
    for (size_t i = 0; i < 8; ++i) {
        hash[i * 4 + 0] = (state[i] >> 24) & 0xFF;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xFF;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xFF;
        hash[i * 4 + 3] = (state[i] >> 0) & 0xFF;
    }
    return hash;
}

void SHA256::reset() {
    buffer.fill(0);
    bufferLength = 0;
    bitLength = 0;

    state = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
}

inline uint32_t SHA256::rotateRight(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

inline uint32_t SHA256::choose(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

inline uint32_t SHA256::majority(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint32_t SHA256::sigma0(uint32_t x) {
    return rotateRight(x, 2) ^ rotateRight(x, 13) ^ rotateRight(x, 22);
}

inline uint32_t SHA256::sigma1(uint32_t x) {
    return rotateRight(x, 6) ^ rotateRight(x, 11) ^ rotateRight(x, 25);
}

inline uint32_t SHA256::delta0(uint32_t x) {
    return rotateRight(x, 7) ^ rotateRight(x, 18) ^ (x >> 3);
}

inline uint32_t SHA256::delta1(uint32_t x) {
    return rotateRight(x, 17) ^ rotateRight(x, 19) ^ (x >> 10);
}

void SHA256::processBlock() {
    array<uint32_t, 64> m{};
    for (size_t i = 0; i < 16; ++i) {
        m[i] = (buffer[i * 4 + 0] << 24) |
               (buffer[i * 4 + 1] << 16) |
               (buffer[i * 4 + 2] << 8) |
               (buffer[i * 4 + 3]);
    }
    for (size_t i = 16; i < 64; ++i) {
        m[i] = delta1(m[i - 2]) + m[i - 7] + delta0(m[i - 15]) + m[i - 16];
    }

    auto a = state[0], b = state[1], c = state[2], d = state[3];
    auto e = state[4], f = state[5], g = state[6], h = state[7];

    for (size_t i = 0; i < 64; ++i) {
        uint32_t t1 = h + sigma1(e) + choose(e, f, g) + K[i] + m[i];
        uint32_t t2 = sigma0(a) + majority(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
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
