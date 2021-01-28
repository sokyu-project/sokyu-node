#include "Bucket.h"

Bucket::Bucket(PeerManager& pm, int depth, int kvalue) : pm(pm), depth(depth), kvalue(kvalue)
{
    touch();
}

Bucket::~Bucket()
{

}

bool Bucket::isEmpty() const
{
    return dqPeers.empty();
}

bool Bucket::isFull() const
{
    return dqPeers.size() == kvalue;
}

int Bucket::getDepth() const
{
    return depth;
}

int Bucket::getKValue() const
{
    return kvalue;
}

bool Bucket::canHoldPeer(const Hash& id) const
{
    std::bitset<160> bits = id.toBitSet();
    auto lastBits = 160 - prefixSize;
    for (auto bit = 159; bit >= lastBits; bit--)
    {
        if (prefix[bit] ^ bits[bit]) return false;
    }
    return true;
}

bool Bucket::addPeer(Peer&& p)
{
    for (std::deque<Peer>::iterator it = dqPeers.begin(); it!=dqPeers.end(); it++)
    {
        if (p.compare((*it))) // a peer with that ID is already in this bucket
        {
            dqPeers.erase(it); // replace it with the new version
            dqPeers.emplace_back(std::move(p));
            touch();
            return true;
        }
    }

    if (isFull())
    {
        // bucket is full, but no peer to replace, add into replacements
        dqReplacements.emplace_back(std::move(p));
        return false;
    }

    dqPeers.emplace_back(std::move(p));

    touch();
    return true;
}

bool Bucket::removePeer(Hash id)
{
    for (std::deque<Peer>::iterator it = dqPeers.begin(); it!=dqPeers.end(); it++)
    {
        if ((*it).compareHash(id))
        {
            dqPeers.erase(it);
            return true;
        }
    }
    return false;
}

void Bucket::touch()
{
    // todo update the timestamp here
}
