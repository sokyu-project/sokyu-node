#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

// An object which represents an IP Address

class Address
{
    public:
        Address(std::string addressString, int port, int type);
        virtual ~Address();

    protected:

    private:
        std::string addr;
        int port;

        int type; // 0 IPv4, 1 IPv6
};

#endif // ADDRESS_H
