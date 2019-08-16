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

TEST_CASE("10 KG Space Miner falling in gravity field for some time" ) {

    SpaceMiner spc(10,20);
    spc.tick();
    spc.tick();
    spc.tick();

    SECTION("Falls") {
        REQUIRE( spc.speed() == 60);
    }
}


TEST_CASE("10 KG Space Miner falling in earth gravity field for some time" ) {

    SpaceMiner spc(10,10);
    spc.tick();
    spc.tick();
    spc.tick();

    SECTION("Falls") {
        REQUIRE( spc.speed() == 30);
    }
}

TEST_CASE("Space miner 100m above ground" ) {

    SpaceMiner spc(10, 20);
    
    spc.tick();

    SECTION("Descends 10m in one tick") {
        int height = spc.height();
        REQUIRE(height == 90);
    }

    SECTION("Descends another 30m in one tick") {
        spc.tick();
        int height = spc.height();
        //s = ut + ½ at²
        // 20 + 10
        REQUIRE(height == 60);
    }
}
