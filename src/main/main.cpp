#include <iostream>
#include "World.h"
#include "InPipe.h"
#include "OutPipe.h"
#include "SpaceMiner.h"


int *HEIGHT = new int(1000);
int *SPEED = new int(0);
int *CRASH_SPEED = new int(-1);

int main()
{
    // Output the hello world text
    //World().greet();
    //InPipe().forever();
    // while(true) {
    //     InPipe().loop();
    //     OutPipe().loop();
    // }
    SpaceMiner spc(10,10,*HEIGHT);
    ThrottlePostionFactory factory(48, 95, 190);
  
    std::function<void(int)> observer1 = [](int i) { *HEIGHT = i; };
    std::function<void(int)> speedObserver = [](int i) { *SPEED = i; };
    std::function<void(int)> crashObserver = [](int i) { *CRASH_SPEED = i; };
  
    spc.addHeightObserver(observer1);
    spc.addSpeedObserver(speedObserver);
    spc.addCrashObserver(crashObserver);

    
    bool notDone = true;
    while(notDone) {       

        if(*SPEED > 3) {
            spc.engine(factory.high());
        } else if(*SPEED > 2) {
            spc.engine(factory.medium());
        } else if(*SPEED > 1) {
            spc.engine(factory.low());
        } else {
            spc.engine(factory.closed());
        }

        cout << "HEIGHT " << *HEIGHT << " SPEED " << *SPEED << "\n";

        spc.tick();

        notDone = *CRASH_SPEED < 0;
    }

    cout << "CRASH SPEED " << *CRASH_SPEED << "\n";


    return 0;
} 