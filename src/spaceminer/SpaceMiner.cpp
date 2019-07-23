#include "SpaceMiner.h"
#include <iostream>

SpaceMiner::SpaceMiner(int pmass, int accelerationDueToGravity)
{
    this->mass = pmass;
    this->currentSpeed = 0;
    this->currentThrust = 0;
    this->accelerationDueToGravity = accelerationDueToGravity;
}

int SpaceMiner::speed()
{
    return this->currentSpeed;
}

void SpaceMiner::thrust(int newtons)
{
    this->currentThrust = newtons; 
}

void SpaceMiner::tick()
{
    int speedDueToThrust = this->currentThrust / this->mass;
    this->currentSpeed +=  speedDueToThrust + accelerationDueToGravity;
}