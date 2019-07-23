#include "SpaceMiner.h"
#include <iostream>

SpaceMiner::SpaceMiner(int pmass)
{
    this->mass = pmass;
    this->currentSpeed = 0;
    this->currentThrust = 0;
    std::cout << "SpaceMiner(int pmass = )" << pmass << std::endl;
}

SpaceMiner::~SpaceMiner() {
    std::cout << "~SpaceMiner()" << std::endl;
}

SpaceMiner::SpaceMiner(const SpaceMiner &sm2)
{
    this->currentSpeed = sm2.currentSpeed;
    this->currentThrust = sm2.currentThrust;
    this->mass = sm2.mass;
    std::cout << "SpaceMiner(const SpaceMiner &sm2)" << std::endl;
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
    this->currentSpeed = this->currentSpeed + (this->currentThrust / this->mass);
}