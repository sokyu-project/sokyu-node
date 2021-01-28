#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <thread>
#include <atomic>
#include <mutex>

#include "NetworkHandler.h"

// Simple TCP server we will use to communicate with other nodes and respond to requests

typedef unsigned char byte;

class Server
{
    public:
        Server(int port);
        virtual ~Server();

        bool init();
        bool run(std::unique_ptr<NetworkHandler>& handler);
        void shutdown();

        std::atomic<bool> shouldStop;

        void addSocket(int newSocket);

    protected:

    private:
        int port;

        int sockfd;
        byte buffer[2048];

        fd_set clientFds;
        std::mutex socketsMutex;
        int clientSockets[50];
        int maxClients = 50;

        struct sockaddr_in servaddr;

        std::thread sThread;
};

#endif // SERVER_H
