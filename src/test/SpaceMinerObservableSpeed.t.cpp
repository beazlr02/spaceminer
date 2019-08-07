#include "catch.hpp"
#include "SpaceMiner.h"
#include <functional>

class CapturingThing
{
    public:
        int value;
};

TEST_CASE("Observing speed" ) {

    SpaceMiner spc(10);
    spc.thrust(100);
    
    CapturingThing *thing= new CapturingThing();

    std::function<void(int)> observer = [thing](int i) { thing->value = i; };

    spc.addSpeedObserver(observer);

    spc.tick();

    SECTION("observes speed") {
        REQUIRE( thing->value == 10);
    }
}


TEST_CASE("Observing speed with multiple observers" ) {

    SpaceMiner spc(10);
    spc.thrust(100);
    
    CapturingThing *thing= new CapturingThing();
    CapturingThing *otherThing= new CapturingThing();

    std::function<void(int)> observer1 = [thing](int i) { thing->value = i; };
    std::function<void(int)> observer2 = [otherThing](int i) { otherThing->value = i; };

    spc.addHeightObserver(observer1);
    spc.addHeightObserver(observer2);

    spc.tick();

    SECTION("everyone observes speed") {
        REQUIRE( thing->value == 95);
        REQUIRE( otherThing->value == 95);
    }
}
