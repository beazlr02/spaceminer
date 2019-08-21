#include "SpaceMiner.h"
#include <iostream>
#include <math.h>

SpaceMiner::SpaceMiner(int pmass, int accelerationDueToGravity, int heightAboveGroundInMeters)
{
    this->mass = pmass;
    this->currentSpeed = 0;
    this->currentThrust = 0;
    this->currentHeight = heightAboveGroundInMeters; //CoV
    this->accelerationDueToGravity = accelerationDueToGravity;
    this->impactSpeed = -1;
}

void SpaceMiner::tick()
{
    int tickTime = 1; //second

    //f = ma => a = f/m
    int accelerationDueToThrust =  this->currentThrust / this->mass;

    //s = ut + ½ at²
    int distanceMoved = this->currentSpeed +  (0.5 * (accelerationDueToGravity - accelerationDueToThrust) * tickTime * tickTime);

    int speedDueToThrust = (-1 * accelerationDueToThrust) / tickTime;
    
    if(distanceMoved > this->currentHeight ) {
        // do some sums to work out speed at impact
        int distanceRemaining = this->currentHeight;
        
        if(this->impactSpeed == -1) {
          //v² = u² + 2as
          this->setImpactSpeed( sqrt( (this->currentSpeed * this->currentSpeed) + ( 2 * (this->accelerationDueToGravity * distanceRemaining)) ) );
        }
        //if we hit the ground, signal done?
        //speed should also be zero
        distanceMoved = distanceRemaining;
    }

    this->alterCurrentHeightBy( distanceMoved );
    this->alterSpeedBy( speedDueToThrust + accelerationDueToGravity );
}

//HEIGHT

void SpaceMiner::alterCurrentHeightBy(int descentAmount) {
    this->currentHeight = this->currentHeight - descentAmount;
    for(int i = 0 ; i < this->observers.size() ; i++) {
        Obs o = this->observers.at(i);
        o(this->currentHeight);
    }
}

int SpaceMiner::height()
{
    return this->currentHeight;
}

void SpaceMiner::addHeightObserver(std::function<void(int)> &observer) {
    this->observers.push_back(observer);
}

//SPEED

void SpaceMiner::alterSpeedBy(int newSpeed) {
    this->currentSpeed += newSpeed;
    for(int i = 0 ; i < this->speedObservers.size() ; i++) {
        Obs o = this->speedObservers.at(i);
        o(this->speed());
    }
}

int SpaceMiner::speed()
{
    return abs(this->currentSpeed);
}

void SpaceMiner::addSpeedObserver(Obs &observer) {
    this->speedObservers.push_back(observer);
}



int SpaceMiner::speedAtImpact()
{
    return this->impactSpeed;
}

void SpaceMiner::setImpactSpeed(int speed)
{
    this->impactSpeed = speed;
    for(int i = 0 ; i < this->crashObservers.size() ; i++) {
        Obs o = this->crashObservers.at(i);
        o(this->impactSpeed);
    }
}

void SpaceMiner::addCrashObserver(Obs &observer) {
    this->crashObservers.push_back(observer);
    if(this->impactSpeed != -1) {
            observer(this->impactSpeed);
    }
}


void SpaceMiner::thrust(int newtons)
{
    this->currentThrust = newtons; 
}

void SpaceMiner::engine(ThrottlePostion postion)
{
    this->thrust(postion.thrustInNewtons);
}

