#include <cest/cest.h>

#include <inih/INIReader.h>

#define DefaultValue(x)   x
#define Section(x)        x
#define Name(x)           x


describe("inih (INI Not Invented Here)", []() {
    it("parses an ini file into a reader class", []() {
        INIReader reader("../tests/sample.ini");

        expect(reader.Get("parameter")).toBe("value");
    });

    it("parses ini contents from a string into a reader class", []() {
        std::string ini_contents =
        "[animals] \n \
        cats_colour = black ; meow";

        INIReader reader(ini_contents.c_str(), ini_contents.size());

        expect(reader.Get(Section("animals"), Name("cats_colour"), DefaultValue(""))).toBe("black");
    });

    it("reports the first invalid line in the ini file when parsing invalid ini contents", []() {
        std::string ini_contents =
        "[section] \n \
        parameter  value";

        INIReader reader(ini_contents.c_str(), ini_contents.size());

        expect(reader.ParseError()).toBe(2);
    });

    it("reports -1 when the target ini file could not be opened", []() {
        INIReader reader("/wrong/path/to/file.ini");

        expect(reader.ParseError()).toBe(-1);
    });

    it("parses an ini file with sections", []() {
        INIReader reader("../tests/sample_with_sections.ini");

        expect(reader.Get(Section("first"), Name("parameter"), DefaultValue(""))).toBe("value");
        expect(reader.Get(Section("second"), Name("parameter"), DefaultValue(""))).toBe("other_value");
    });

    it("is able to parse different data types", []() {
        INIReader reader("../tests/sample.ini");

        expect(reader.GetBoolean(Section(""), Name("boolean"), DefaultValue(false))).toBe(true);
        expect(reader.GetBoolean(Section(""), Name("other_boolean"), DefaultValue(false))).toBe(true);
        expect(reader.GetInteger(Section(""), Name("integer"), DefaultValue(0))).toBe(66);
        expect(reader.GetReal(Section(""), Name("double"), DefaultValue(0))).toBe(1.3445);
    });

    it("can tell whether a parameter exists or not", []() {
        INIReader reader("../tests/sample.ini");

        expect(reader.HasValue(Section(""), Name("parameter"))).toBe(true);
        expect(reader.HasValue(Section(""), Name("does not exist"))).toBe(false);
    });
});
