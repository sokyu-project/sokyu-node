#include "Peer.h"

Peer::Peer()
{
    //ctor
}

Peer::~Peer()
{
    //dtor
}

Address Peer::getAddress()
{
//    return addr;
}

Hash& Peer::getID()
{
    return id;
}

bool Peer::compare(Peer& otherPeer)
{
    return compareHash(otherPeer.getID());
}

bool Peer::compareHash(Hash& hash)
{
    return this->id.compare(hash);
}
