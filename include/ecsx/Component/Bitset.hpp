#ifndef BITSET_HPP_INCLUDED
#define BITSET_HPP_INCLUDED

#include <bitset>
#include <iostream>

namespace ecsx::component {

    template<std::size_t N>
    class Bitset : std::bitset<N> {
    public:
        using std::bitset<N>::operator[];
        Bitset();
        bool contains(const Bitset& other) const;
    };

}

#include <Bitset.inl>

#endif // BITSET_HPP_INCLUDED
