#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("10 KG Space Miner at rest in gravity field" ) {

    SpaceMiner spc(10, 20);

    SECTION("Initial speed") {
        REQUIRE( spc.speed() == 0);
    }
}

TEST_CASE("10 KG Space Miner fallingc in gravity field" ) {

    SpaceMiner spc(10,20);
    spc.tick();

    SECTION("Falls") {
        REQUIRE( spc.speed() == 20);
    }
}

TEST_CASE("10 KG Space Miner fallingc in gravity field for some time" ) {

    SpaceMiner spc(10,20);
    spc.tick();
    spc.tick();
    spc.tick();

    SECTION("Falls") {
        REQUIRE( spc.speed() == 60);
    }
}
