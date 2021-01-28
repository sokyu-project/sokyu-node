#ifndef NODE_H
#define NODE_H

#include <string>

#include "Network.h"
#include "Blockchain.h"

class Node
{
    public:
        Node();
        virtual ~Node();

        bool start(void);
        bool loadArgs(int argc, char* argv[]);

    protected:

    private:
        Network nw;
        Blockchain bc;

        int port = 9000;

        std::string initialAddress = "";
        int initialPort = 0;
};

#endif // NODE_H
