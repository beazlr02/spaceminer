#include "catch.hpp"
#include "SpaceMiner.h"
#include <functional>

class CapturingThing
{
    public:
        int value;
};

TEST_CASE("Observing height" ) {

    SpaceMiner spc(10);
    spc.thrust(100);
    spc.tick();


    CapturingThing *thing= new CapturingThing();

    std::function<void(int)> observer = [thing](int i) { thing->value = i; };

    spc.addHeightObserver(observer);

    SECTION("observes speed") {
        REQUIRE( thing->value == 10);
    }
}
