#ifndef NETWORK_H
#define NETWORK_H

#include "Peer.h"
#include "PeerManager.h"
#include "NetworkHandler.h"
#include "Server.h"
#include "Client.h"

typedef unsigned char byte;

class Network
{
    public:
        Network();
        virtual ~Network();

        bool init(int port);
        void discoverPeers(Peer seedPeer);                      // sends a request to the Seed Peer for a list of peers

        static Packet* decode(byte* buffer);
        static byte* encode(Packet p);

        void processPackets();

        void shutdown();

        void initialConnect(std::string address, int port);

    protected:

    private:
        std::unique_ptr<Server> server;
        std::unique_ptr<Client> client;
        std::unique_ptr<PeerManager> pm;
        std::unique_ptr<NetworkHandler> nh;
};

#endif // NETWORK_H
