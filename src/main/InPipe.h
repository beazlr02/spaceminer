#include <fstream>

using namespace std;

class InPipe {
    private:
        ifstream handle;
        void pipe();
        void readOneLine();
    public:
        InPipe();
        void forever();
        void loop();
};