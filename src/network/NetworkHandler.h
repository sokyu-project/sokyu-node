#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include "Packet.h"
#include "PeerManager.h"

#include <mutex>
#include <condition_variable>
#include <deque>

class Client;

class NetworkHandler
{
    public:
        NetworkHandler(Client& cli, PeerManager& pm);
        virtual ~NetworkHandler();

        void handlePacket(Packet p, int sock);

        void processOne();

    protected:

    private:
        Client& cli;
        PeerManager& pm;

        void respond(Packet p, int sock);

        std::mutex mutex;
        std::condition_variable cond;
        std::deque<std::pair<Packet, int>> queue;

        void quePush(std::pair<Packet, int> pair);
        std::pair<Packet, int> quePop();
};

#endif // NETWORKHANDLER_H
