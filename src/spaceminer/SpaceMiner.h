#include <functional>

class SpaceMiner
{
    private:
     int mass;
     int currentSpeed;
     int currentThrust;
     int accelerationDueToGravity;
     int currentHeight;
     int impactSpeed;

    public:
     SpaceMiner(int mass, int accelerationDueToGravity = 0);
     int speed();
     void thrust(int newtons);
     void tick();
     int height();
     int speedAtImpact();
     void addHeightObserver(std::function<void(int)>);
};