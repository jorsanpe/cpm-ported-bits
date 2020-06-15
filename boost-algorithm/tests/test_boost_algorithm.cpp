#include <cest/cest.h>
#include <boost/algorithm/string.hpp>

using namespace cest;
using namespace std;


describe("boost-algorithm", []() {
    it("trims a string", []() {
        string str = "Hello    ";
        boost::trim_if(str, boost::is_any_of(" "));
        expect(str).toBe("Hello");
    });

    it("splits a string", []() {
        vector<string> tokens;
        string str = "A,B,C";
        boost::split(tokens, str, boost::is_any_of(","));
        expect(tokens).toBe({"A", "B", "C"});
    });
});
