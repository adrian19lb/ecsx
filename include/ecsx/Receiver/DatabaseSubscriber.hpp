#ifndef DATABASESUBSCRIBER_HPP_INCLUDED
#define DATABASESUBSCRIBER_HPP_INCLUDED

#include <Subscriber.hpp>

namespace ecsv::receiver {

    template<typename T, typename R>
    class DatabaseSubscriber : public Subscriber<T> {
    public:
        R* subscribedDatabase;
    };
}


#endif // DATABASESUBSCRIBER_HPP_INCLUDED
