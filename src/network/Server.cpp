#include "Server.h"

#include "Logger.h"
#include "Network.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef unsigned char byte;

Server::Server(int port) : port(port)
{
    std::atomic_init(&shouldStop, false);
}

Server::~Server()
{
    //dtor
}

bool Server::init()
{
    Logger::info("Starting server.");
    for (int i = 0; i < maxClients; i++)
    {
        clientSockets[i] = 0;
    }


    sockfd = socket(AF_INET, SOCK_STREAM, 0);  // master socket creation
    if (sockfd == -1)
    {
        Logger::error("Failed to create socket.");
        return false;
    }

    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)1,   // allow multiple connections
          sizeof(1)) < 0 )
    {
        Logger::warning("Allowing multiple connections failed.");
    }

    servaddr.sin_family = AF_INET;                  // our address
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))<0)
    {
        Logger::error("Failed to bind to port.");
        return false;
    }

    Logger::info("Starting to listen on port "+std::to_string(port));

    if (listen(sockfd, 5) < 0)
    {
        Logger::error("Failed to start listening");
        return false;
    }

    Logger::info("Server initialization successful.");
    return true;
}

bool Server::run(std::unique_ptr<NetworkHandler>& handler)
{
    Logger::info("Starting server thread.");

    sThread = std::thread([this, &handler]() mutable {
        int addrlen = sizeof(servaddr);

        while(!shouldStop)
        {
            //for (int i=0; i<sizeof(buffer); i++)
            for (int i=0; i<2048; i++)
            {
                buffer[i] = 0;
            }

            FD_ZERO(&clientFds);

            FD_SET(sockfd, &clientFds);

            int max_sd = sockfd;

            for (int i=0; i<maxClients; i++)
            {
                int sd = clientSockets[i];

                if (sd > 0) FD_SET(sd, &clientFds);

                if (sd > max_sd) max_sd = sd;
            }

            struct timeval tv = {1, 0};
            int activity = select(max_sd+1, &clientFds, NULL, NULL, &tv);

            if (FD_ISSET(sockfd, &clientFds) && !shouldStop)
            {
                int newSocket;

                if ((newSocket = accept(sockfd, (struct sockaddr*)&servaddr, (socklen_t*)&addrlen)) < 0)
                {
                    Logger::error("Accept failure.");
                    return false;
                }

                Logger::info("New connection");

                //for (int i=0; i<maxClients; i++)
                //{
                //    if (clientSockets[i]==0)
                //    {
                //        clientSockets[i]=newSocket;
                //        Logger::info("Added into socket holder.");

                //        break;
                //    }
                //}

                addSocket(newSocket);
            }

            for (int i=0; i<maxClients; i++)
            {
                int sd = clientSockets[i];

                if (FD_ISSET(sd, &clientFds))
                {
                    byte buffer[1024];
                    int value = read(sd, buffer, 1024);             // here we fill the buffer with stuff
                    if (value==0) // disconnected
                    {
                        getpeername(sd, (struct sockaddr*)&servaddr, (socklen_t*)&addrlen);
                        Logger::info("Someone disconnected. Closing his socket.");
                       // Logger::info("Disconnected: "+inet_ntoa(servaddr.sin_addr)+":"+ntohs(servaddr.sin_port));

                        close(sd);
                        clientSockets[i]=0;
                    } else
                    {
                        //std::string str;
                        //for (int i=0; i<value; i++)
                        //{
                        //    str += buffer[i];
                        //}
                        //Logger::info(str);

                        //buffer[value] = '\0';

                        //char* header = new char[4];

                        //for (int i=0; i<4; i++)
                        //{
                        //    header[i] = buffer[i];
                        //}

                        //std::string msg = "Header: ";
                        //msg+=header;
                        //Logger::info(msg);

                        //std::string ret;

                        //unsigned char code[4] = {25, 32, 195, 227};    // passcode

                        //if (memcmp(header, code, 4) == 0)    // this message came from an instance of our program, process it
                        //{
                            //Logger::info("One of ours.");
                            //ret = "Welcome\n";

                            //byte* insCode = new byte[4];
                            //for (int i=0; i<sizeof(insCode); i++)
                            //{
                                //insCode[i] = buffer[4+i];
                            //}

                            //byte* paySize = new byte[4];
                            //for (int i=0; i<sizeof(paySize); i++)
                            //{
                                //paySize[i] = buffer[8+i];
                            //}

                            //uint32_t paySizeInt = 0;
                            //for (int i=0; i<4; i++)
                            //{
                                //paySizeInt <<= 8;
                                //paySizeInt |= paySize[i];
                            //}


                            //byte* payload = new byte[paySizeInt];
                            //for (int i=0; i<sizeof(payload); i++)
                            //{
                                //payload[i] = buffer[12+i];
                            //}


                            //Packet p(insCode, paySizeInt, payload);


                        Packet* p = Network::decode(buffer);

                        if (p != nullptr)
                        {
                            handler->handlePacket(*p, sd);
                        }

                        delete p;

                        //ret = "Packet receieved.\n";  // have it say this for right now

                        //for (int i=0; i<sizeof(ret); i++)
                        //{
                        //    buffer[i] = ret[i];
                        //}

                        //send(sd, buffer, sizeof(buffer), 0);

                    }
                }
            }
        }

        sleep(2);
        Logger::info("Should stop");
    });

    //serverThread.join();

    //Logger::info("Slfjauf432uouoi324532434");

    return true;
}

void Server::shutdown()
{
    Logger::info("Stopping server.");
    sThread.detach();
    shouldStop = true;
    //sThread.join();
    //Logger::info("After");
}

void Server::addSocket(int newSocket)
{
    const std::lock_guard<std::mutex> lock(socketsMutex);
    for (int i=0; i<maxClients; i++)
    {
        if (clientSockets[i]==0)
        {
            clientSockets[i]=newSocket;
            Logger::info("Added into socket holder.");

            break;
        }
    }
}
