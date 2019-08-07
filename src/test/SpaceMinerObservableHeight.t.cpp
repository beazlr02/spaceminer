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
    
    CapturingThing *thing= new CapturingThing();

    std::function<void(int)> observer = [thing](int i) { thing->value = i; };

    spc.addHeightObserver(observer);

    spc.tick();

    SECTION("observes speed") {
        REQUIRE( thing->value == 95);
    }
}


TEST_CASE("Observing height with multiple observers" ) {

    SpaceMiner spc(10);
    spc.thrust(100);
    
    CapturingThing *thing= new CapturingThing();
    CapturingThing *otherThing= new CapturingThing();

    std::function<void(int)> observer1 = [thing](int i) { thing->value = i; };
    std::function<void(int)> observer2 = [otherThing](int i) { otherThing->value = i; };

    spc.addSpeedObserver(observer1);
    spc.addSpeedObserver(observer2);

    spc.tick();

    SECTION("everyone observes speed") {
        REQUIRE( thing->value == 10);
        REQUIRE( otherThing->value == 10);
    }
}
