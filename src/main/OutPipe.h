#include <fstream>
#include <string>

using namespace std;

class OutPipe {
    private:
        string nextStringToSend;
        ofstream handle;
        void pipe();
    public:
        OutPipe();
        void forever();
        void loop();
        void sendString(string toSend);
};