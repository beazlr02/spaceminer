class SpaceMiner
{
    private:
     int mass;
     int currentSpeed;
    public:
     SpaceMiner(int mass);
     int speed();
     void thrust(int newtons);
};