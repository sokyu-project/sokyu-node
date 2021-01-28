#ifndef PACKET_H
#define PACKET_H

#include "inttypes.h"

// An object that represents a packet of data, to be sent and received over the network.
// They are serialized and deserialized inside the Peer objects.

typedef unsigned char byte;

class Packet
{
    public:
        Packet(uint32_t code, uint32_t paysize, byte* payload);
        virtual ~Packet();

        byte* getPayload();
        uint32_t getPSize();
        uint32_t getICode();

    protected:

    private:
        uint32_t instructionCode;
        uint32_t payloadSize;
        byte* payload;

};

#endif // PACKET_H
