#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("Space miner at constant velocity 10m/s 100m above ground" ) {

// hard coded 100 in implementation
//s = ut + ½ at²
    SpaceMiner spc(10);
    ThrottlePostionFactory factory(20, 40, 100);
    spc.engine(factory.high());
    
    spc.tick();
    SECTION("Falls") {
        REQUIRE( spc.speed() == 10);
    }

    SECTION("Descends 5m in one tick") {
        int height = spc.height();
        REQUIRE(height == 105);
    }

    SECTION("Descends another 15m in one tick") {
        spc.tick();
        int height = spc.height();
        REQUIRE(height == 120);
    }
}

TEST_CASE("Space miner at constant velocity 10m/s 1000m above ground" ) {

// hard coded 100 in implementation
//s = ut + ½ at²
    SpaceMiner spc(10,0,1000);
    ThrottlePostionFactory factory(20, 40, 100);
    spc.engine(factory.high());
    
    spc.tick();
    SECTION("Moves 5m in one tick") {
        int height = spc.height();
        REQUIRE(height == 1005);
    }
}
