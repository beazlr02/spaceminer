#include "SpaceMiner.h"
#include <iostream>

SpaceMiner::SpaceMiner(int pmass, int accelerationDueToGravity)
{
    this->mass = pmass;
    this->currentSpeed = 0;
    this->currentThrust = 0;
    this->currentHeight = 100; //CoV
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
    int tickTime = 1; //second

    int accelerationDueToThrust =  this->currentThrust / this->mass;



    //s = ut + ½ at²
    int distanceMoved = this->currentSpeed +  (0.5 * accelerationDueToThrust);


    int speedDueToThrust = accelerationDueToThrust / tickTime;
    
    this->currentSpeed +=  speedDueToThrust + accelerationDueToGravity;


    this->currentHeight = this->currentHeight - distanceMoved;
}

int SpaceMiner::height()
{
    return this->currentHeight;
}