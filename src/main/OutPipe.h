#include <fstream>

using namespace std;

class OutPipe {
    private:
        ofstream handle;
        void pipe();
    public:
        OutPipe();
        void forever();
        void loop();
};