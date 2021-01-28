#include "Network.h"

#include "Logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <iterator>

Network::Network()
{

}

Network::~Network()
{
    //dtor
}

bool Network::init(int port)
{
    server = std::make_unique<Server>(port);
    if (!server->init())
    {
        Logger::error("Failed to set up server.");
        return false;
    }

    client = std::make_unique<Client>(*server);

    pm = std::make_unique<PeerManager>(*this, 5);

    nh = std::make_unique<NetworkHandler>(*client, *pm);

    server->run(nh);

    //server->shutdown();

    return true;
}

void Network::discoverPeers(Peer seedPeer)
{
    Address seedAddress = seedPeer.getAddress();
}

Packet* Network::decode(byte* buffer)         // utility function to decode network data and put it into a packet object.
{
    Logger::info("decoding");

    byte* header = new byte[4];
    for (int i=0; i<4; i++)
    {
        header[i] = buffer[i];
    }

    unsigned char code[4] = {25, 32, 195, 227};    // passcode

    if (memcmp(header, code, 4) == 0)    // this message came from an instance of our program, process it
    {
        Logger::info("One of ours.");

        //byte* insCode = new byte[4];
        //for (int i=0; i<4; i++)
        //{
        //    insCode[i] = buffer[i];
        //}

        uint32_t insCodeInt = int((byte)(buffer[4]) << 24 |
        (byte)(buffer[5]) << 16 |
        (byte)(buffer[6]) << 8 |
        (byte)(buffer[7]));
        //for (int i=0; i<4; i++)
        //{
        //    insCodeInt <<= 8;
        //    insCodeInt |= insCode[4+i];
        //}

        //byte* paySize = new byte[4];
        //for (int i=0; i<4; i++)
        //{
        //    paySize[i] = buffer[8+i];
        //}

        //std::cout << "InsCodeInt decoded: " << insCodeInt << std::endl;

        uint32_t paySizeInt = int((byte)(buffer[8]) << 24 |
        (byte)(buffer[9]) << 16 |
        (byte)(buffer[10]) << 8 |
        (byte)(buffer[11]));
        //for (int i=0; i<4; i++)
        //{
        //    paySizeInt <<= 8;
        //    paySizeInt |= paySize[i];
        //}

        //std::cout << "PaySizeInt decoded: " << paySizeInt << std::endl;

        byte* payload = new byte[paySizeInt];
        for (int i=0; i<paySizeInt; i++)
        {
            payload[i] = buffer[12+i];
        }

        return new Packet(insCodeInt, paySizeInt, payload);


    } else {    // this message came from a different program, ignore it
        Logger::info("Ignoring message.");
        return NULL;
    }
}

byte* Network::encode(Packet p)
{
    byte* buffer = new byte[2048];

    for (int i=0; i<2048; i++) // zero the buffer
    {
        buffer[i] = 0;
    }

    for (int i=0; i<4; i++) // load the passcode {25, 32, 195, 227}
    {
        buffer[0] = 25;
        buffer[1] = 32;
        buffer[2] = 195;
        buffer[3] = 227;
    }

    uint32_t insCode = p.getICode();     // load the instruction code
    buffer[4] = (insCode >> 24) & 0xFF;
    buffer[5] = (insCode >> 16) & 0xFF;
    buffer[6] = (insCode >> 8) & 0xFF;
    buffer[7] = insCode & 0xFF;

    uint32_t paySize = p.getPSize(); // load the payload size
    buffer[8] = (paySize >> 24) & 0xFF;
    buffer[9] = (paySize >> 16) & 0xFF;
    buffer[10] = (paySize >> 8) & 0xFF;
    buffer[11] = paySize & 0xFF;

    byte* payload = p.getPayload();

    for (int i=0; i<paySize; i++) // load the payload/data
    {
        buffer[12+i] = payload[i];
    }

    return buffer;
}

void Network::processPackets()
{
    nh->processOne();
}

void Network::shutdown()
{
    server->shutdown();
}

void Network::initialConnect(std::string address, int port)
{
    //unsigned char* text = (unsigned char*) strtol("Ping", NULL, 10);
    unsigned char text[5] = {4,5,6,7,8};
    Packet p(0, std::size(text), text);
    //std::cout << "PaySizeInt encoding: (should be 5) " << std::size(text) << std::endl;
    if(!(client->sendPacket(p, address, port)))
    {
        Logger::error("Unable to contact the Initial Peer.");
    }

    //Logger::info("Can we get here?");
}
