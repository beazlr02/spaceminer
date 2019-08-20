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
    ThrottlePostionFactory factory(20, 40, 100);
    spc.engine(factory.high());
    
    CapturingThing *speedObserver= new CapturingThing();

    std::function<void(int)> observer = [speedObserver](int i) { speedObserver->value = i; };

    spc.addSpeedObserver(observer);

    spc.tick();

    SECTION("observes speed") {
        REQUIRE( speedObserver->value == 10);
    }
}


TEST_CASE("Observing speed with multiple observers" ) {

    SpaceMiner spc(10);
    ThrottlePostionFactory factory(20, 40, 100);
    spc.engine(factory.high());
    
    CapturingThing *speedObserver= new CapturingThing();
    CapturingThing *otherSpeedObserver= new CapturingThing();

    std::function<void(int)> observer1 = [speedObserver](int i) { speedObserver->value = i; };
    std::function<void(int)> observer2 = [otherSpeedObserver](int i) { otherSpeedObserver->value = i; };

    spc.addSpeedObserver(observer1);
    spc.addSpeedObserver(observer2);

    spc.tick();

    SECTION("everyone observes speed") {
        REQUIRE( speedObserver->value == 10);
        REQUIRE( otherSpeedObserver->value == 10);
    }
}
