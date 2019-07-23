#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("10 KG Space Miner at rest" ) {

    SpaceMiner spc(10);

    SECTION("Initial speed") {
        int s = spc.speed();
        REQUIRE( s == 0);
    }

    SECTION("One second pulse of 20N thrust  ") {
        spc.thrust(20);
        int s = spc.speed();
        REQUIRE( s == 2);
    }

    SECTION("One second pulse of 40N thrust  ") {
        spc.thrust(40);
        int s = spc.speed();
        REQUIRE( s == 4);
    }
}


TEST_CASE("20 KG Space Miner at rest" ) {

    SpaceMiner spc(20);

    SECTION("Initial speed") {
        int s = spc.speed();
        REQUIRE( s == 0);
    }

    SECTION("One second pulse of 20N thrust  ") {
        spc.thrust(20);
        int s = spc.speed();
        REQUIRE( s == 1);
    }

    SECTION("One second pulse of 40N thrust  ") {
        spc.thrust(40);
        int s = spc.speed();
        REQUIRE( s == 2);
    }
}

TEST_CASE("10KG Space Miner MOVING" ) {
    SpaceMiner spc(10);
    spc.thrust(40);

    SECTION("Initial speed is 4") {
        int s = spc.speed();
        REQUIRE(s == 4);
    }

    SECTION("One second pulse of 20N trust") {
        spc.thrust(20);
        int s = spc.speed();
        REQUIRE(s == 6);
    }
}