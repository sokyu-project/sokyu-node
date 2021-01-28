#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "Packet.h"
#include "Server.h"

typedef unsigned char byte;

class Client
{
    public:
        Client(Server& serv);
        virtual ~Client();

        bool init();
        void sendPacket(Packet p, int socket);
        bool sendPacket(Packet p, std::string address, int port);

    protected:

    private:
        Server& serv;

        int port;
        std::string stAddress;

        int sockfd;
        byte buffer[2048];

        struct sockaddr_in addr;
};

#endif // CLIENT_H
