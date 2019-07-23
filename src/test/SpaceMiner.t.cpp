#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("10 KG Space Miner at rest" ) {

    SpaceMiner spc(10);

    SECTION("Initial speed") {
        REQUIRE( spc.speed() == 0);
    }
}

TEST_CASE("10 KG Space Miner trusting" ) {

    SpaceMiner spc(10);
    spc.thrust(20);

    SECTION("Before Tick still initial speed") {
        REQUIRE( spc.speed() == 0);
    }
}


TEST_CASE("20 KG Space Miner at rest" ) {

    SpaceMiner spc(20);

    SECTION("Initial speed") {
        REQUIRE( spc.speed() == 0);
    }

    SECTION("One second pulse of 20N thrust  ") {
        spc.thrust(20);
        spc.tick();
        REQUIRE( spc.speed() == 1);
    }
}

TEST_CASE("10 KG Space Miner thrusting along" ) {

    SpaceMiner spc(10);
    spc.thrust(20);
    spc.tick();

    SECTION("One second pulse of 20N thrust  ") {
        REQUIRE( spc.speed() == 2);
    }

    SECTION("One second pulse of 40N thrust  ") {
        spc.thrust(40);
        spc.tick();
        REQUIRE( spc.speed() == 6);
    }
}
