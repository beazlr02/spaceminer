Done

A basic physics engine
The lander has MASS
The lander starts at speed ZERO
The lander accepts a command to fire a thruster - almost
Move from method call per second to a ticking clock
There is GRAVITY to apply constant force
The thruster slows the lander down - almost, uses negative thrust value

The lander has height above the ground and reports that height as it changes - you have to ask
The lander stops when it hits the ground
The lander reports HEIGHT to an observer
The lander reports SPEED to an observer
announce crash at speed

Todo

Clean up lots of CODE
Hardcoded HEIGHT needs removing
Change thruster to take be off, half, full levels
Remove observers
Pipe adapters
remove primitive obsession



//// Thrust reworking

    spc.thrust(100);
    spc.thrust(-10);
    spc.thrust(40);
    spc.thrust(-40);       SECTION("One second pulse of 40N breaking  ") {
    spc.thrust(20);

add new method that takes an object describing the magnitude of how open the throttle is


