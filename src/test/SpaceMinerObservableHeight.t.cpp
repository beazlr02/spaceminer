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
    ThrottlePostionFactory factory(20, 40, 100);
    spc.engine(factory.high());
    
    
    CapturingThing *heightObserver= new CapturingThing();

    std::function<void(int)> observer = [heightObserver](int i) { heightObserver->value = i; };

    spc.addHeightObserver(observer);

    spc.tick();

    SECTION("observes speed") {
        REQUIRE( heightObserver->value == 105);
    }
}



TEST_CASE("Observing height with multiple observers" ) {

    SpaceMiner spc(10);
    ThrottlePostionFactory factory(20, 40, 100);
    spc.engine(factory.high());
    
    CapturingThing *heightObserver= new CapturingThing();
    CapturingThing *otherHeightObserver= new CapturingThing();

    std::function<void(int)> observer1 = [heightObserver](int i) { heightObserver->value = i; };
    std::function<void(int)> observer2 = [otherHeightObserver](int i) { otherHeightObserver->value = i; };

    spc.addHeightObserver(observer1);
    spc.addHeightObserver(observer2);

    spc.tick();

    SECTION("everyone observes speed") {
        REQUIRE( heightObserver->value == 105);
        REQUIRE( otherHeightObserver->value == 105);
    }
}
