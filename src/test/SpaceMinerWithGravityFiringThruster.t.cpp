#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("10 KG Space Miner fallingc in gravity field for some time with thruster" ) {

    ThrottlePostionFactory throttle(10, 50, 100);
    SpaceMiner spc(10,10);
    spc.tick();
    spc.tick();
    spc.tick();

    //s = ut + ½ at²
    // 20 + 10

    //f = ma
    //
    spc.engine(throttle.low());
    spc.tick();

    SECTION("Falls") {
        REQUIRE( spc.speed() == 39);
    }
}
