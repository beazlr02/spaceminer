#include "SpaceMiner.h"

SpaceMiner::SpaceMiner()
{
    mass = 10;
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
        // 2=a
        // s = 2 m/s
    currentSpeed = (newtons / mass);
}