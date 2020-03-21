/*
 * This file is just a sample. Find the full Cest project at https://github.com/cegonse/cest
 */
#include <cest/cest.h>


describe("Cest testing framework", []() {
    it("asserts various data types", []() {
        expect(true).toBe(true);
        expect("string").toBe("string");
        expect(10).toBe(10);
    });
});
