#include "InPipe.h"
#include <sys/types.h>  // mkfifo
#include <sys/stat.h>   // mkfifo
#include <stdio.h>
#include <iostream>
#include <string>

InPipe::InPipe() : handle() 
{
    cout << "InPipe::InPipe()" << '\n';
}
void InPipe::forever()
{
    while (true)
    {
        loop();
    }
}
void InPipe::loop()
{    
    cout << "loop" << '\n';
    if ( ! handle.is_open() )
    {
        pipe();   
    }

    readOneLine();
}
void InPipe::readOneLine()
{
    string line;
    if(getline(handle, line))  
    {
        cout << line << '\n';
    }
    else
    {
        cout << "close" << '\n';
        handle.close();
        pipe();
    }
}
void InPipe::pipe() {
    cout << "mkfifo" << '\n';
    int fifo = mkfifo("/tmp/fifo", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
    handle.open("/tmp/fifo");
    cout << "madefifo" << '\n';
}