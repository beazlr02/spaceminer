#include <iostream>
#include "World.h"
#include "InPipe.h"
#include "OutPipe.h"

int main()
{
    // Output the hello world text
    World().greet();
    InPipe().forever();
    // while(true) {
    //     InPipe().loop();
    //     OutPipe().loop();
    // }
    return 0;
} 