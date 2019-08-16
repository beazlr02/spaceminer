#include "SpaceMiner.h"
#include <iostream>
#include <math.h>

SpaceMiner::SpaceMiner(int pmass, int accelerationDueToGravity)
{
    this->mass = pmass;
    this->currentSpeed = 0;
    this->currentThrust = 0;
    this->currentHeight = 100; //CoV
    this->accelerationDueToGravity = accelerationDueToGravity;
    this->impactSpeed = -1;
}

int SpaceMiner::speed()
{
    return abs(this->currentSpeed);
}

void SpaceMiner::thrust(int newtons)
{
    this->currentThrust = newtons; 
}

void SpaceMiner::tick()
{
    int tickTime = 1; //second

    //f = ma => a = f/m
    int accelerationDueToThrust =  this->currentThrust / this->mass;

    //s = ut + ½ at²
    int distanceMoved = this->currentSpeed +  (0.5 * (accelerationDueToGravity - accelerationDueToThrust));

    int speedDueToThrust = (-1 * accelerationDueToThrust) / tickTime;
    
    int toMoveTo = this->currentHeight - distanceMoved;

    if(toMoveTo < 0 ) {
        // do some sums to work out speed at impact
        int distanceRemaining = this->currentHeight;
        
        if(this->impactSpeed == -1) {
          //v² = u² + 2as
          this->impactSpeed = sqrt( (this->currentSpeed * this->currentSpeed) + ( 2 * (this->accelerationDueToGravity * distanceRemaining)) );
                
            for(int i = 0 ; i < this->crashObservers.size() ; i++) {
                Obs o = this->crashObservers.at(i);
                o(this->impactSpeed);
            }
        }
        //if we hit the ground, signal done?

        this->currentHeight = 0;
    } else {
        this->currentHeight = toMoveTo;
    }
    //current speed is actually a velocity towards ground
    this->currentSpeed +=  speedDueToThrust + accelerationDueToGravity;

    for(int i = 0 ; i < this->observers.size() ; i++) {
        Obs o = this->observers.at(i);
        o(this->currentHeight);
    }


    for(int i = 0 ; i < this->speedObservers.size() ; i++) {
        Obs o = this->speedObservers.at(i);
        o(this->speed());
    }
}

int SpaceMiner::height()
{
    return this->currentHeight;
}

int SpaceMiner::speedAtImpact()
{
    return this->impactSpeed;
}

void SpaceMiner::addHeightObserver(std::function<void(int)> &observer) {
    this->observers.push_back(observer);
}

void SpaceMiner::addSpeedObserver(Obs &observer) {
    this->speedObservers.push_back(observer);
}

void SpaceMiner::addCrashObserver(Obs &observer) {
    this->crashObservers.push_back(observer);
    if(this->impactSpeed != -1) {
            observer(this->impactSpeed);
    }
}

void SpaceMiner::engine(ThrottlePostion postion)
{
    this->thrust(postion.thrustInNewtons);
}

