#include <cest/cest.h>

#include <string.h>
#include <blake3/blake3.h>


describe("BLAKE3 hashing function", []() {
    it ("hashes values", []() {
        blake3_hasher hasher;
        char input[] = "An input";
        uint8_t output[BLAKE3_OUT_LEN];
        uint8_t expected_output[BLAKE3_OUT_LEN] = { 
            0x17, 0x52, 0x13, 0xf5, 0x62, 0xad, 0xaf, 0x67, 
            0x4e, 0x13, 0x0b, 0x7c, 0x3b, 0xd4, 0xa5, 0xaa, 
            0x4a, 0xa7, 0xaa, 0x8d, 0x43, 0xa0, 0x99, 0x73, 
            0x66, 0x82, 0x47, 0x51, 0xff, 0xd5, 0x8e, 0xa8
         };

        blake3_hasher_init(&hasher);
        blake3_hasher_update(&hasher, input, strlen(input));
        blake3_hasher_finalize(&hasher, output, BLAKE3_OUT_LEN);

        expect(output).toEqualMemory(expected_output, BLAKE3_OUT_LEN);
    });
});
