#ifndef BUCKET_H
#define BUCKET_H

//#include "PeerManager.h"

#include "Peer.h"

#include <deque>
#include <chrono>
#include <utility>
#include <bitset>

class PeerManager;

/*!
 * Represents a bucket for use by the Kademlia algorithm to store Peers.
 */

class Bucket
{
    public:
        Bucket(PeerManager& pm, int depth, int kvalue);
        ~Bucket();

        bool isEmpty() const;
        bool isFull() const;

        int getDepth() const;
        int getKValue() const;

        bool canHoldPeer(const Hash& id) const;

        /*!
         * Attempts to insert the supplied peer. Returns true if successful.
         */

        bool addPeer(Peer&& p);

        /*!
         * Attempts to remove the peer with the supplied ID. Returns true if successful.
         */

        bool removePeer(Hash id);

    private:
        PeerManager& pm;

        /*!
         * The deque which holds the peers contained in this bucket.
         */

        std::deque<Peer> dqPeers{};

        std::deque<Peer> dqReplacements{};

        int depth;
        int kvalue;

        std::bitset<160> prefix;
        std::size_t prefixSize{0};

        //mutable std::chrono::steady_clock::time_point tpLastUpdated;

        void touch();
};


#endif
