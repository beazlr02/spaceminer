#include "catch.hpp"
#include "SpaceMiner.h"
#include "InputPipe.h"
#include <fstream>

#include <iostream>

#include <sys/types.h>  // mkfifo
#include <sys/stat.h>   // mkfifo
#include <thread>
class FifoInputPipe : public InputPipe
{
    private:
        std::thread t;
        ifstream fifoHandle;
        const char* path;
        void openFifo();
        void startThreadForPipeMGMT();

    public:
        FifoInputPipe(const char* path);
        std::string line();
};

void FifoInputPipe::startThreadForPipeMGMT()
{
    //guard
    this->t = std::thread( &FifoInputPipe::openFifo, this);
}

void FifoInputPipe::openFifo()
{
    cout << "Thread started to open fifo " << this->path <<'\n';
    int mkfifoResult = mkfifo(this->path, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
    cout << "Thread mkfifio " << mkfifoResult << '\n';

    //guard
    if(mkfifoResult != 0 ) {
        cout << "Thread guarded" << '\n';
        return;
    }

    cout << "This " << this << " fifo " << &(this->fifoHandle) << " path " << this->path << '\n';
    this->fifoHandle.open(this->path);  
    cout << "Opened fifio" << '\n';
}

FifoInputPipe::FifoInputPipe(const char* path) : fifoHandle(), path(path), t(&FifoInputPipe::openFifo, this)
{
    //startThreadForPipeMGMT();
    cout << "Construction complete" << '\n';
}

std::string FifoInputPipe::line()
{
    this->t.join();
    if ( ! fifoHandle.is_open() )
    {
        //startThreadForPipeMGMT();   
        return "closed";
    } else {
        return "The expected line";
    }
    
}

bool fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}


TEST_CASE("Reading from a pipe" ) {

    //create a new client to miner pipe adapter
    //need to know the filepath for the pipe

    
    SECTION("reads as a line") 
    {
        char name2[L_tmpnam];
        if (std::tmpnam(name2)) {
            std::cout << "temporary file name: " << name2 << '\n';
        }
        const char* path = name2;
        FifoInputPipe lePipe{path};

        cout << "Starting first test" << '\n';
        ofstream handle;
        cout << "test handle open" << '\n';
        while( !fileExists(path) ) {
            std::this_thread::sleep_for(1s);
        }
        handle.open(path);
        cout << "test writing to handle" << '\n';
        handle << "The expected line" << '\n';

        //read that line
        std::string line = lePipe.line();

        handle.close();

        REQUIRE( line == "The expected line");
    }
/*
    SECTION("reads as a newline because no newline recieved yet") 
    {
    }

    SECTION("reads as a newline after client closes")
    {

    }

    SECTION("reads as a line after client closes")
    {

    }
    */
}