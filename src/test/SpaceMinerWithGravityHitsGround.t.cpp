#include "catch.hpp"
#include "SpaceMiner.h"


TEST_CASE("10 KG Space Miner fallingc in gravity field and hits the ground" ) {

    SpaceMiner spc(10,20);

    /* 
    s = ut + ½ at²
    100 = 20t² / 2
    200 = 20t²
    10 = t²
    t = 3.16
    t ==> 4
     */

    spc.tick();
    spc.tick();
    spc.tick();
    spc.tick();

    SECTION("Hits the ground") {
        REQUIRE( spc.height() <= 0);
    }

    SECTION("Speed at impact") {
    /* 
    t = 3.16
    v = u + at
    v = 0 + 3.16*20

    v = 63.24

     */

        REQUIRE( spc.speedAtImpact() == 63 );

    }

    SECTION("Stays on the ground") {
        spc.tick();
        REQUIRE( spc.height() <= 0);
    }
}

