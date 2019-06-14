#include "OutPipe.h"
#include <sys/types.h>  // mkfifo
#include <sys/stat.h>   // mkfifo

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

OutPipe::OutPipe() : handle()
{
    cout << "OutPipe::OutPipe()" << '\n';
    int fifo = mkfifo("/tmp/fifo", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
}


void OutPipe::forever()
{
    while (true)
    {
        loop();
    }
}

void OutPipe::loop()
{
    
    if (handle.is_open())
    {
        handle << "oot oot oot" << '\n';
    }
    else
    {
        cout << "Unable to open file";
        pipe();
        handle << "oot oot oot" << '\n';
    }
}

void OutPipe::pipe()
{
    int fifo = mkfifo("/tmp/fifo", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
    handle.open("/tmp/fifo");
}