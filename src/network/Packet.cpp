#include "Packet.h"

typedef unsigned char byte;

Packet::Packet(uint32_t code, uint32_t paysize, byte* payload)
    : instructionCode(code), payloadSize(paysize), payload(payload)
{

}

Packet::~Packet()
{
    //dtor
}

byte* Packet::getPayload()
{
    return payload;
}

uint32_t Packet::getPSize()
{
    return payloadSize;
}

uint32_t Packet::getICode()
{
    return instructionCode;
}
