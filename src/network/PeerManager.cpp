#include "PeerManager.h"

PeerManager::PeerManager(Network& network, int kvalue) : network(network), kvalue(kvalue)
{
    //ctor
}

PeerManager::~PeerManager()
{
    //dtor
}

std::vector<Address> PeerManager::getAddresses(int amount)
{

}

void PeerManager::addPeer(Peer&& peer)
{

}

void PeerManager::removePeer(const Hash& id)
{

}

std::vector<Peer> findNeighbors(Hash const &id)
{

}

size_t getBucketIndex(const Hash& id)
{

}
