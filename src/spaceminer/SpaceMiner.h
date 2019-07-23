class SpaceMiner
{
    private:
     int mass;
     int currentSpeed;
     int currentThrust;
     int accelerationDueToGravity;

    public:
     SpaceMiner(int mass, int accelerationDueToGravity = 0);
     int speed();
     void thrust(int newtons);
     void tick();
};