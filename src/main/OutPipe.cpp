#include "OutPipe.h"
#include <sys/types.h>  // mkfifo
#include <sys/stat.h>   // mkfifo

#include <stdio.h>
#include <iostream>

using namespace std;

OutPipe::OutPipe() : handle(), nextStringToSend()
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
    if ( ! handle.is_open())
    {
        pipe();
    }
    
    handle << nextStringToSend << '\n';
}

void OutPipe::pipe()
{
    int fifo = mkfifo("/tmp/fifo", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
    handle.open("/tmp/fifo");
}

void OutPipe::sendString(string toSend)
{
    nextStringToSend = toSend;
}