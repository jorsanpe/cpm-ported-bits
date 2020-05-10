#include <spdlog/spdlog.h>
#include <cest/cest.h>

using namespace cest;


describe("spdlog", []() {
    it("writes logs with defined criticality", []() {
        auto console = spdlog::stdout_color_mt("console");
        console->info("Welcome to spdlog!");
    });
});