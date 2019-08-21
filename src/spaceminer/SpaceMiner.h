#include <functional>
#include <vector>

class ThrottlePostion
{
    public:
      int thrustInNewtons;
      ThrottlePostion(int newtons) : thrustInNewtons{newtons} {};  
};

class ThrottlePostionFactory
{
    private:
        int lowValue;
        int mediumValue;
        int highValue;

    public: 
        ThrottlePostionFactory(int low, int medium, int high) : lowValue{low}, mediumValue{medium}, highValue{high} {};
        ThrottlePostion closed() {return ThrottlePostion(0);}
        ThrottlePostion low() {return ThrottlePostion(lowValue);}
        ThrottlePostion medium() {return ThrottlePostion(mediumValue);}
        ThrottlePostion high() {return ThrottlePostion(highValue);}
};

class SpaceMiner
{


    public:
     SpaceMiner(int mass, int accelerationDueToGravity = 0, int heightAboveGroundInMeters = 100);
     int speed();
     void engine(ThrottlePostion position);
     void tick();
     int height();
     int speedAtImpact();
    
     using Obs = std::function<void(int)>;
     void addHeightObserver(Obs&);
     void addSpeedObserver(Obs&);
     void addCrashObserver(Obs&);



    private:
     int mass;
     int currentSpeed;
     int currentThrust;
     int accelerationDueToGravity;
     int currentHeight;
     int impactSpeed;
     std::vector<Obs> observers;
     std::vector<Obs> speedObservers;
     std::vector<Obs> crashObservers;
     void thrust(int newtons);
     void alterCurrentHeightBy(int);
     void alterSpeedBy(int);
     void setImpactSpeed(int);
};
