#include "Client.h"
#include "Logger.h"
#include "Network.h"

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <bits/stdc++.h>

Client::Client(Server& serv) : serv(serv)
{
    //ctor
}

Client::~Client()
{
    //dtor
}

bool Client::init()
{
    Logger::info("Initializing client instance...");
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        Logger::error("Failed to create client socket.");
        return false;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    char charAddress[stAddress.length()+1];
    strcpy(charAddress, stAddress.c_str());

    if (inet_pton(AF_INET, charAddress, &addr.sin_addr)<=0)
    {
        Logger::error("Address is invalid, conversion to binary failed.");
        return false;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr))<0)
    {
        Logger::error("Connection to target failed.");
        return false;
    }
}

void Client::sendPacket(Packet p, int socket)
{
    Logger::info("Sending packet with InsCode "+std::to_string(p.getICode()));
    byte* buf = Network::encode(p);

    //Logger::info("Send packet 2");
    send(socket, buf, (4+4+4+(p.getPSize())), 0); // send

    //byte* returnBuffer = new byte[2048];

    //int valread = read(socket, returnBuffer, sizeof(returnBuffer));

    //Packet* returnPacket = Network::createPacket(returnBuffer);

    //return returnPacket;
}

bool Client::sendPacket(Packet p, std::string address, int port)
{
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        Logger::error("Failed to create client socket.");
        return false;
    }

    struct sockaddr_in tempAddr;

    tempAddr.sin_family = AF_INET;
    tempAddr.sin_port = htons(port);

    char charAddress[address.length()+1];
    strcpy(charAddress, address.c_str());

    if (inet_pton(AF_INET, charAddress, &tempAddr.sin_addr)<=0)
    {
        Logger::error("Address is invalid, conversion to binary failed.");
        return false;
    }

    if (connect(sock, (struct sockaddr *)&tempAddr, sizeof(tempAddr))<0)
    {
        Logger::error("Connection to target failed.");
        return false;
    }


    sendPacket(p, sock);

    serv.addSocket(sock);
    // TODO add the new socket into the socket holder of the server so we can listen for replies. DONE

    return true;
}
