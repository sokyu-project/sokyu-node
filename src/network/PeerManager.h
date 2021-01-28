#ifndef PEERMANAGER_H
#define PEERMANAGER_H

#include <vector>
#include <deque>
#include <memory>

#include "Address.h"
#include "Peer.h"
#include "Bucket.h"

class Network;

// An object that holds the Peers
// This is the routing table

class PeerManager
{
    public:
        PeerManager(Network& network, int kvalue);
        virtual ~PeerManager();

        std::vector<Address> getAddresses(int amount);

        void addPeer(Peer&& p);
        void removePeer(const Hash& id);

        std::vector<Peer> findNeighbors(Hash const &id) const;

        size_t getBucketIndex(const Hash& id) const;

    protected:

    private:
        Network& network;
        int kvalue;

        std::deque<Bucket> dqBuckets;
};

#endif // PEERMANAGER_H
