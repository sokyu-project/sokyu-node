#include <iostream>
#include "Node.h"

#include "Hash.h"

using namespace std;

int main(int argc, char* argv[])
{
    Hash h1 = Hash::random();

    std::cout << h1.toString() << std::endl;

    Node node;

    if (argc > 1)
    {
        if(!node.loadArgs(argc, argv))
        {
            return -1;
        }
    }

    if (!node.start())
    {
        return -1;
    }

    return 0;
}
