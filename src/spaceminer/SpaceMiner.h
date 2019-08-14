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
    public: 
        static ThrottlePostion closed() {return ThrottlePostion(0);}
        static ThrottlePostion low() {return ThrottlePostion(-10);}
        static ThrottlePostion high() {return ThrottlePostion(-100);}
};

class SpaceMiner
{


    public:
     SpaceMiner(int mass, int accelerationDueToGravity = 0);
     int speed();
     void thrust(int newtons);
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

};
