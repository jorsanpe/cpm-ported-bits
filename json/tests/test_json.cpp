#include <cest/cest.h>
#include <json/json.hpp>

using namespace cest;
using namespace nlohmann;


describe("JSON for Modern C++", []() {
    it("parses a JSON string", []() {
        json json_object = json::parse(
            "{"
                "\"Image\": {"
                    "\"Animated\": false,"
                    "\"Height\": 600,"
                    "\"IDs\": [116,943,234,38793],"
                    "\"Thumbnail\": {"
                        "\"Height\": 125,"
                        "\"Url\": \"http://www.example.com/image/481989943\","
                        "\"Width\": 100"
                    "},"
                    "\"Title\": \"View from 15th Floor\","
                    "\"Width\": 800"
                "}"
            "}"
        );

        expect(json_object["Image"]["Animated"]).toBe(false);
        expect(json_object["Image"]["IDs"][0]).toBe(116);
        expect(json_object["Image"]["Thumbnail"]["Url"]).toBe("http://www.example.com/image/481989943");
    });

    it("dumps a JSON string", []() {
        json json_object = {
            {"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {
                {"everything", 42}
            }},
            {"list", {1, 0, 2}},
            {"object", {
                {"currency", "USD"},
                {"value", 42.99}
           }}
        };

        expect(json_object.dump()).toBe(
                "{"
                    "\"answer\":{"
                        "\"everything\":42"
                    "},"
                    "\"happy\":true,"
                    "\"list\":[1,0,2],"
                    "\"name\":\"Niels\","
                    "\"nothing\":null,"
                    "\"object\":{"
                        "\"currency\":\"USD\","
                        "\"value\":42.99"
                    "},"
                    "\"pi\":3.141"
        "}");
    });
});
