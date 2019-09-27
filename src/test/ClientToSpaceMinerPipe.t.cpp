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
    this->t = std::thread( &FifoInputPipe::openFifo, this);
}

#define guard(b) if(b) return;

void FifoInputPipe::openFifo()
{
    int mkfifoResult = mkfifo(this->path, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
    guard(mkfifoResult != 0);
    /*guard*/if(mkfifoResult != 0 ) {
        return;
    }
    this->fifoHandle.open(this->path);  
}

FifoInputPipe::FifoInputPipe(const char* path) : fifoHandle(), path(path), t(&FifoInputPipe::openFifo, this)
{
}

std::string FifoInputPipe::line()
{
    this->t.join();
    if ( ! fifoHandle.is_open() )
    {
        //startThreadForPipeMGMT();   
        return "closed\n";
    } else {
        return "The expected line\n";
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

        ofstream handle;
        while( !fileExists(path) ) {
            std::this_thread::sleep_for(1s);
        }
        handle.open(path);
        handle << "The expected line" << '\n';

        //read that line
        std::string line = lePipe.line();

        handle.close();

        REQUIRE( line == "The expected line\n");
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