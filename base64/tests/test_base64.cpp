#include <cest/cest.h>

#include <base64/base64.h>

using namespace cest;
using namespace std;


describe("base64 encoder/decoder", []() {
    it("encodes and decodes string in base64", []() {
        string to_encode = "string to encode";

        expect(base64_encode((unsigned char *)to_encode.c_str(), to_encode.size())).toBe("c3RyaW5nIHRvIGVuY29kZQ==");
        expect(base64_decode("c3RyaW5nIHRvIGVuY29kZQ==")).toBe("string to encode");
    });
});