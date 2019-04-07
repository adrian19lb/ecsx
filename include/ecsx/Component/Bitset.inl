namespace ecsx::component {

    template<size_t N> Bitset<N>::Bitset()
    : std::bitset<N>() {

    }

    template<size_t N> bool Bitset<N>::contains(const Bitset& other) const {
        if ( (other & *this) == *this ) {
            return true;
        }else {
            return false;
        }
    }



}
