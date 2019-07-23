#include "SpaceMiner.h"

SpaceMiner::SpaceMiner(int pmass)
{
    mass = pmass;
    currentSpeed = 0;
}

int SpaceMiner::speed()
{
    return currentSpeed;
}


void SpaceMiner::thrust(int newtons)
{
        // f=ma
        // 20=10a
        // 20/10=a
        // 2=a
        // s = 2 m/s
    currentSpeed += (newtons / mass);
}