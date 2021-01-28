#ifndef HASH_H
#define HASH_H

#include <cstdint>
#include <array>
#include <string>
#include <bitset>

/*!
 * Represents a 160-bit (20 bytes) hash.
 */

class Hash
{
    public:
        Hash();
        virtual ~Hash();

        /*!
         * Creates a new hash and gives it a random value.
         */

        static Hash random();

        std::uint8_t& at(std::size_t index);
        std::uint8_t* getData();
        std::size_t getSize();
        void setAt(int index, uint32_t value);
        std::uint32_t getAt(int index);

        std::string toString();

        /*!
         * Returns true if this hash and the supplied hash are the same.
         */

        bool compare(Hash& otherHash);

        std::bitset<160> toBitSet() const;

    private:
        std::array<std::uint32_t, 5> data;
};

#endif // HASH_H
