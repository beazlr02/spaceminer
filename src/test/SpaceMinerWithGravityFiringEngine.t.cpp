#include "catch.hpp"
#include "SpaceMiner.h"

TEST_CASE("Using throttle controls" ) {

    SpaceMiner spc(10,10);
    spc.tick();
    spc.tick();
    spc.tick();

    ThrottlePostionFactory factory(20, 50, 100);

    spc.engine(factory.high());
    spc.tick();

    SECTION("Engine at full") {
        REQUIRE( spc.speed() == 30);
    }

    SECTION("Throttle still open") {
        spc.tick();
        REQUIRE( spc.speed() == 30);
    }

    SECTION("Throttle closed") {
        spc.engine(factory.closed());
        spc.tick();
        REQUIRE( spc.speed() == 40);
    }

    SECTION("Throttle a little open") {
        spc.engine(factory.low());
        spc.tick();
        REQUIRE( spc.speed() == 38);
    }

    SECTION("Throttle half open") {
        spc.engine(factory.medium());
        spc.tick();
        REQUIRE( spc.speed() == 35);
    }
}
