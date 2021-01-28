#include "NetworkHandler.h"

#include <iostream>
#include <new>
#include <sched.h>

#include "Client.h"
#include "Logger.h"

#define SIGNEDTOUNSIGNED(v) (v > 255 ? 255 : (v < 0 ? 0 : v))

NetworkHandler::NetworkHandler(Client& cli, PeerManager& pm) : cli(cli), pm(pm)
{
    //ctor
}

NetworkHandler::~NetworkHandler()
{
    //dtor
}

void NetworkHandler::handlePacket(Packet p, int sock)
{
    //byte x[5] = {1,2,3,4,5};
    //Packet randomPacket(0, 5, x);
    std::pair<Packet, int> newPair = std::make_pair(p, sock);
    quePush(newPair);
    //std::lock_guard<std::mutex> lock(mutex);
}

void NetworkHandler::respond(Packet p, int sock)
{
    cli.sendPacket(p, sock);
}

void NetworkHandler::quePush(std::pair<Packet, int> pair)
{
    //std::unique_lock<std::mutex> lock(mutex);
    std::lock_guard<std::mutex> lock(mutex);
    queue.push_front(pair);
    //int x = pair.second;
    //cond.notify_one();
}

std::pair<Packet, int> NetworkHandler::quePop()
{
    //std::unique_lock<std::mutex> lock(mutex);
    //cond.wait(lock, [=]{ return !queue.empty(); });
    //std::lock_guard<std::mutex> lock(mutex);
    std::pair<Packet, int> ret(std::move(queue.back()));
    queue.pop_back();
    return ret;
}

void NetworkHandler::processOne()
{
    if (!queue.empty())
    {
        //std::pair<Packet, int> thisPair = queue.back();
        std::pair<Packet, int> thisPair = quePop();

        Packet p = thisPair.first;
        int sock = thisPair.second;

        Logger::info("Handling packet with instruction code: "+std::to_string(p.getICode()));

        int code = p.getICode();
        if (code == 0)  // ping
        {
            Logger::info("Handling type 0 packet: ping");
            //unsigned char* responseText = (unsigned char*) strtol("Pong", NULL, 10);    // TODO work on converting data into bytes to be sent
            unsigned char responseText[5] = {4,5,6,7,8};
            Packet response(1, 5, responseText);
            respond(response, sock);
        } else if (code == 1)   // pong
        {
            Logger::info("We got a response back on that ping we just sent.");
        } else if (code == 2)   // peer handshake
        {

        }
    }
}
