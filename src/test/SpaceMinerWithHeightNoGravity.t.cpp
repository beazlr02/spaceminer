#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("Space miner at constant velocity 10m/s 100m above ground" ) {

// hard coded 100 in implementation
//s = ut + ½ at²
    SpaceMiner spc(10);
    spc.thrust(100);
    spc.tick();
    SECTION("Falls") {
        REQUIRE( spc.speed() == 10);
    }

    SECTION("Descends 5m in one tick") {
        int height = spc.height();
        REQUIRE(height == 95);
    }

    SECTION("Descends another 15m in one tick") {
        spc.tick();
        int height = spc.height();
        REQUIRE(height == 80);
    }
}
