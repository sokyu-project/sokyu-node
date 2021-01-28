#include "Address.h"

Address::Address(std::string addressString, int port, int type) : addr(addressString), port(port), type(type)
{
    //ctor
}

Address::~Address()
{
    //dtor
}
