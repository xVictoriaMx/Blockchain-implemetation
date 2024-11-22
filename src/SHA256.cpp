#include "SHA256.h"

using namespace std;

class SHA256 {
public:
    static const size_t HashSize = 32;

    SHA256() { reset(); }

    void update(const uint8_t* data, size_t length) {
        for (size_t i = 0; i < length; ++i) {
            buffer[bufferLength++] = data[i];
            if (bufferLength == BlockSize) {
                processBlock();
                bitLength += BlockSize * 8;
                bufferLength = 0;
            }
        }
    }

    array<uint8_t, HashSize> finalize() {
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

    void reset() {
        buffer.fill(0);
        bufferLength = 0;
        bitLength = 0;

        state = {
            0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
            0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
        };
    }

private:
    static const size_t BlockSize = 64;

    array<uint32_t, 8> state{};
    array<uint8_t, BlockSize> buffer{};
    size_t bufferLength = 0;
    uint64_t bitLength = 0;

    static inline uint32_t rotateRight(uint32_t x, uint32_t n) {
        return (x >> n) | (x << (32 - n));
    }

    static inline uint32_t choose(uint32_t x, uint32_t y, uint32_t z) {
        return (x & y) ^ (~x & z);
    }

    static inline uint32_t majority(uint32_t x, uint32_t y, uint32_t z) {
        return (x & y) ^ (x & z) ^ (y & z);
    }

    static inline uint32_t sigma0(uint32_t x) {
        return rotateRight(x, 2) ^ rotateRight(x, 13) ^ rotateRight(x, 22);
    }

    static inline uint32_t sigma1(uint32_t x) {
        return rotateRight(x, 6) ^ rotateRight(x, 11) ^ rotateRight(x, 25);
    }

    static inline uint32_t delta0(uint32_t x) {
        return rotateRight(x, 7) ^ rotateRight(x, 18) ^ (x >> 3);
    }

    static inline uint32_t delta1(uint32_t x) {
        return rotateRight(x, 17) ^ rotateRight(x, 19) ^ (x >> 10);
    }

    void processBlock() {
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

    static constexpr array<uint32_t, 64> K = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };
};