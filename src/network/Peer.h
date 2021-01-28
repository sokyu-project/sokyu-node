#ifndef PEER_H
#define PEER_H

#include "Packet.h"
#include "Address.h"
#include "Hash.h"

class Hash;

// An object that represents a peer who may be connected to and interacted with

typedef unsigned char byte;

class Peer
{
    public:
        Peer();
        virtual ~Peer();

        Address getAddress();
        Hash& getID();

        /*!
         * Returns true if this peer and the supplied peer have the same hash.
         */

        bool compare(Peer& otherPeer);

        /*!
         * Returns true if this peer's hash matches the supplied hash.
         */

        bool compareHash(Hash& hash);

    protected:

    private:
       // Address addr("0.0.0.0", 9000, 1);                       // the IP Address of this peer
       Hash id;
};

#endif // PEER_H
