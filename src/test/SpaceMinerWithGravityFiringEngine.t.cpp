#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("Using throttle controls" ) {

    SpaceMiner spc(10,10);
    spc.tick();
    spc.tick();
    spc.tick();

    spc.engine(ThrottlePostionFactory::high());
    spc.tick();

    SECTION("Engine at full") {
        REQUIRE( spc.speed() == 30);
    }

    SECTION("Throttle still open") {
        spc.tick();
        REQUIRE( spc.speed() == 30);
    }

    SECTION("Throttle still open") {
        spc.engine(ThrottlePostionFactory::closed());
        spc.tick();
        REQUIRE( spc.speed() == 40);
    }

    SECTION("Throttle a little open") {
        spc.engine(ThrottlePostionFactory::low());
        spc.tick();
        REQUIRE( spc.speed() == 39);
    }
}
