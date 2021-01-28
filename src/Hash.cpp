#include "Hash.h"
#include <cstdint>
#include <stdexcept>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

Hash::Hash()
{

}

Hash::~Hash()
{

}

Hash Hash::random()
{
    Hash newHash;
    srand(time(NULL));
    for (int i=0; i<newHash.getSize(); i++)
    {
        uint32_t r = rand() % UINT_MAX-1 + 0;
        //newHash.at(i) = r;
        newHash.setAt(i, r);
    }

    return newHash;
}

std::uint8_t& Hash::at(std::size_t index)
{
    if (20 <= index)
    {
        throw std::out_of_range("Index is out of bounds.");
    }
    return reinterpret_cast<uint8_t*>(data.data())[index];
}

std::uint8_t* Hash::getData()
{
    return reinterpret_cast<uint8_t*>(data.data());
}

std::size_t Hash::getSize()
{
    return data.size();
}

void Hash::setAt(int index, uint32_t value)
{
    data[index] = value;
}

uint32_t Hash::getAt(int index)
{
    return data[index];
}

std::string Hash::toString()
{
    size_t size = this->getSize();
    char x[size*8];
    std::string str;
    for (int i=0; i<size; i++)
    {
        char x[8];
        sprintf(x, "%x",this->getAt(i));
        std::string newStr(x);
        str += newStr;
    }
    return str;
}

bool Hash::compare(Hash& otherHash)
{
    for (int i=0; i<this->getSize(); i++)
    {
        if (this->getAt(i) != otherHash.getAt(i))
        {
            return false;
        }
    }

    return true;
}

std::bitset<160> Hash::toBitSet() const
{
    std::bitset<160> bs;
    int shiftLeft = 160;
    for (uint32_t part : data)
    {
        shiftLeft -= 32;
        std::bitset<160> bsPart(part);
        bs |= part << shiftLeft;
    }
    return bs;
}
