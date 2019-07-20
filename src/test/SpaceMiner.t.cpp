#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Hello", "[World]" ) {

    SECTION("A message aboot test") {
        int s = 42;
        REQUIRE( s == 42);
    }
}