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
There is a throttle not a thrust in newtons method - Change thruster to take be off, half, full levels
Hardcoded HEIGHT needs removing



Todo

Pipe adapters
Remove observers
remove primitive obsession
speed is zero when on the ground?

Clean up more CODE



Adapters can be ticked

When a command pipe is ticked we 
 - read last command from the pipe and assert the correct action is performed on the space miner
 - read no command and assert nothing happens
 (do we buffer up commands or is it last one wins?) - its last one wins

 - A pipe keeps itself open
 - A pipe will not block reads (actually a pipe will return a \n character if it has an incomplete line in its buffer)
 - A pipe will return character data, whole lines

When a query pipe is ticked we
 - output any changed value as a line of characters, assert is as expected
 - if nothing has changed then nothing output
 - A pipe keeps itself open
 - A pipe will not block writes
 - A pipe will output new line terminated character data

