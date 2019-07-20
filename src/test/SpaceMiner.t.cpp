#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../main/SpaceMiner.h"

TEST_CASE("Hello", "[World]" ) {

    SECTION("A message aboot test") {
    
        SpaceMiner spc;
        int s = spc.speed();
    REQUIRE( s == 42);
    }
}