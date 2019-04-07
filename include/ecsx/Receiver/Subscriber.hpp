#ifndef SUBSCRIBER_HPP_INCLUDED
#define SUBSCRIBER_HPP_INCLUDED

namespace ecsx::receiver {

    template<typename T>
    class Subscriber {
    public:
        virtual void subscribe(const T& subject) = 0;
    };
}

#endif // SUBSCRIBER_HPP_INCLUDED
