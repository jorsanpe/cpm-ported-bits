#include <cest/cest.h>

#include <inih/INIReader.h>


describe("inih (INI Not Invented Here)", []() {
    it("parses an ini file into a reader class", []() {
        INIReader reader("../tests/sample.ini");

        expect(reader.Get("parameter")).toBe("value");
    });
});
