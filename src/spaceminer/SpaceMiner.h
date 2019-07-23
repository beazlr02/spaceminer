class SpaceMiner
{
    private:
     int mass;
     int currentSpeed;
     int currentThrust;
    public:
     SpaceMiner(int mass);
     ~SpaceMiner();
     SpaceMiner(const SpaceMiner &sm2);
     int speed();
     void thrust(int newtons);
     void tick();
};