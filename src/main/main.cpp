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
    ThrottlePostionFactory factory(5, 40, 100);
  
    std::function<void(int)> observer1 = [](int i) { *HEIGHT = i; };
    std::function<void(int)> speedObserver = [](int i) { *SPEED = i; };
    std::function<void(int)> crashObserver = [](int i) { *CRASH_SPEED = i; };
  
    spc.addHeightObserver(observer1);
    spc.addSpeedObserver(speedObserver);
    spc.addCrashObserver(crashObserver);

    while(*CRASH_SPEED < 0) {
        
        cout << "HEIGHT " << *HEIGHT << " SPEED " << *SPEED << "\n";

        spc.tick();
    }

        cout << "CRASH SPEED " << *CRASH_SPEED << "\n";


    return 0;
} 