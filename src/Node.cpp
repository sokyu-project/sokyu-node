#include "Node.h"

#include "Logger.h"

#include <iostream>
#include <signal.h>
#include <cstdlib>
#include <unistd.h>

Node::Node()
{

}

Node::~Node()
{
    //dtor
}

bool shouldExit = false;

void signalInterrupt(int sig)
{
    shouldExit = true;
}

bool Node::start()
{
    Logger::info("Initializing node.");

    signal(SIGINT, signalInterrupt);

    if(!nw.init(port))
    {
        Logger::error("Fatal error setting up the network, program will exit now.");
        return false;
    }

    if (initialPort != 0)
    {
        nw.initialConnect(initialAddress, initialPort);
    }

    while(!shouldExit)
    {
        nw.processPackets();
        sleep(.001);
    }

    Logger::info("Shutting down");

    nw.shutdown();

    return true;
}

bool Node::loadArgs(int argc, char* argv[])
{
    if (argc>=2)
    {
        std::string str1 = argv[1];
        Logger::info("Setting port to "+str1+".");
        try
        {
            port = std::stoi(argv[1]);
        } catch (std::exception const &e)
        {
            Logger::error("Port must be a number.");
            return false;
        }

        if (argc==4)
        {
            Logger::info("Setting initial peer.");
            initialAddress = argv[2];

            try
            {
                initialPort = std::stoi(argv[3]);
            } catch (std::exception const &e)
            {
                Logger::error("Initial Peer port must be a number.");
                return false;
            }
        }
    }

    return true;
}


