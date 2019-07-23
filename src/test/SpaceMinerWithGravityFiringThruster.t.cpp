#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("10 KG Space Miner fallingc in gravity field for some time with thruster" ) {

    SpaceMiner spc(10,10);
    spc.tick();
    spc.tick();
    spc.tick();

    spc.thrust(-10);
    spc.tick();

    SECTION("Falls") {
        REQUIRE( spc.speed() == 39);
    }
}
