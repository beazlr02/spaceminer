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
    const std::string HIGH = "high\n";
    const std::string MEDIUM = "medium\n";
    const std::string LOW = "low\n";
    const std::string CLOSED = "closed\n";

    std::string line = iPipe->line();
    if(line == HIGH) {
        this->engineTrait->engine(this->tpf.high());
    } else if(line == MEDIUM) {
        this->engineTrait->engine(this->tpf.medium());
    } else if(line == LOW) {
        this->engineTrait->engine(this->tpf.low());
    } else if(line == CLOSED) {
        this->engineTrait->engine(this->tpf.closed());
    }
}

TEST_CASE("Parsing messages from the pipe" ) {

    EngineTraitCaptor captor;
    InputPipe iPipe{};
    ThrottlePostionFactory tpf{10,15,20};
    EnginePipeAdapter pipeAdapter{tpf, &captor, &iPipe};

    
    SECTION("high") {
        ThrottlePostion expected{20};
        iPipe.lineToRead = "high\n";
        pipeAdapter.tick();
        REQUIRE( captor.throttlePosition.thrustInNewtons == expected.thrustInNewtons);
    }


    SECTION("medium") {
        ThrottlePostion expected{15};
        iPipe.lineToRead = "medium\n";
        pipeAdapter.tick();
        REQUIRE( captor.throttlePosition.thrustInNewtons == expected.thrustInNewtons);
    }

    SECTION("low") {
        ThrottlePostion expected{10};
        iPipe.lineToRead = "low\n";
        pipeAdapter.tick();
        REQUIRE( captor.throttlePosition.thrustInNewtons == expected.thrustInNewtons);
    }


    SECTION("closed") {
        ThrottlePostion expected{0};
        iPipe.lineToRead = "closed\n";
        pipeAdapter.tick();
        REQUIRE( captor.throttlePosition.thrustInNewtons == expected.thrustInNewtons);
    }


    SECTION("garbage") {
        ThrottlePostion expected{-1};
        iPipe.lineToRead = "garbage\n";
        pipeAdapter.tick();
        REQUIRE( captor.throttlePosition.thrustInNewtons == expected.thrustInNewtons);
    }

    SECTION("no command") {
        ThrottlePostion expected{-1};
        iPipe.lineToRead = "\n";
        pipeAdapter.tick();
        REQUIRE( captor.throttlePosition.thrustInNewtons == expected.thrustInNewtons);
    }
}