#include <functional>
#include <vector>

class SpaceMiner
{


    public:
     SpaceMiner(int mass, int accelerationDueToGravity = 0);
     int speed();
     void thrust(int newtons);
     void tick();
     int height();
     int speedAtImpact();
    
     using Obs = std::function<void(int)>;
     void addHeightObserver(Obs&);
     void addSpeedObserver(Obs&);


    private:
     int mass;
     int currentSpeed;
     int currentThrust;
     int accelerationDueToGravity;
     int currentHeight;
     int impactSpeed;
     std::vector<Obs> observers;
     std::vector<Obs> speedObservers;
     

};