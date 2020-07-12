#include <cest/cest.h>
#include <boost/program_options.hpp>

using namespace cest;
using namespace std;
using namespace boost::program_options;


describe("boost-program-options", []() {
    it("uses default values when command line is empty", []() {
        options_description cmdline_options("boost program options");
        variables_map args;
        int argc = 1;
        const char *argv[] = {
            "program",
            nullptr
        };

        cmdline_options.add_options()
            ("ini,i", value<string>()->default_value("inifile.ini"), "ini file with cpm-hub configuration");
        store(parse_command_line(argc, argv, cmdline_options), args);
        notify(args);

        expect(args["ini"].as<string>()).toBe("inifile.ini");
    });

    it("uses the command line value when option is passed", []() {
        options_description cmdline_options("boost program options");
        variables_map args;
        int argc = 3;
        const char *argv[] = {
            "program",
            "-i",
            "inifile.ini",
            nullptr
        };

        cmdline_options.add_options()
            ("ini,i", value<string>()->default_value("default.ini"), "ini file with cpm-hub configuration");
        store(parse_command_line(argc, argv, cmdline_options), args);
        notify(args);

        expect(args["ini"].as<string>()).toBe("inifile.ini");
    });
});
