#include <cest/cest.h>

#include <sqlite3/sqlite3.h>

using namespace cest;


describe("sqlite3", []() {
    it ("allows opening a database in memory", []() {
        sqlite3 *database;
        char *error_message = NULL;

        expect(sqlite3_open(":memory:", &database)).toBe(SQLITE_OK);
        expect(sqlite3_exec(database, "CREATE TABLE bits( name STRING, version STRING, PRIMARY KEY(name, version));", NULL, NULL, &error_message)).toBe(SQLITE_OK);
        expect(sqlite3_exec(database, "INSERT INTO bits (name, version) VALUES ('sqlite3', '3.32.3');", NULL, NULL, &error_message)).toBe(SQLITE_OK);
    });
});
