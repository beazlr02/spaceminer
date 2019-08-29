#include "catch.hpp"
#include "SpaceMiner.h"

using namespace std;

class EngineTrait
{
    public:
        virtual void engine(ThrottlePostion position) = 0;
};

class EngineTraitCaptor : public EngineTrait
{
    public:
        EngineTraitCaptor() : throttlePosition( ThrottlePostion(-1) ) {};
        ThrottlePostion throttlePosition;
        void engine(ThrottlePostion position){this->throttlePosition = position;}; 
};

class InputPipe
{
    public:
        std::string lineToRead;
        InputPipe();
        std::string line();
};

InputPipe::InputPipe() : lineToRead("")
{

}

std::string InputPipe::line()
{
    return lineToRead;
}


class EnginePipeAdapter
{
    public:
        EngineTrait* engineTrait;
        InputPipe* iPipe;
        ThrottlePostionFactory tpf;
        EnginePipeAdapter(ThrottlePostionFactory tpf, EngineTrait* engineTrait, InputPipe* iPipe);
        void tick();
};

EnginePipeAdapter::EnginePipeAdapter(ThrottlePostionFactory tpf, EngineTrait* engineTrait, InputPipe* iPipe) : tpf(tpf), engineTrait(engineTrait), iPipe(iPipe) {

}

void EnginePipeAdapter::tick()
{
    this->engineTrait->engine(this->tpf.high());
}

/**
 * closed() {return ThrottlePostion(0);}
        ThrottlePostion low() {return ThrottlePostion(lowValue);}
        ThrottlePostion medium() {return ThrottlePostion(mediumValue);}
        ThrottlePostion high(
 */
TEST_CASE("Engine set to full" ) {

    ThrottlePostion expected{20};
    EngineTraitCaptor captor;

    InputPipe iPipe{};
    iPipe.lineToRead = "high\n";
    ThrottlePostionFactory tpf{10,15,20};



    EnginePipeAdapter pipeAdapter{tpf, &captor, &iPipe};

    pipeAdapter.tick();

    SECTION("Initial speed") {
        REQUIRE( captor.throttlePosition.thrustInNewtons == expected.thrustInNewtons);
    }
}