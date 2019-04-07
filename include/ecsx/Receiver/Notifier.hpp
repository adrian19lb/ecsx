#ifndef PROCESORNOTIFIER_HPP_INCLUDED
#define PROCESORNOTIFIER_HPP_INCLUDED

#include <Subscriber.hpp>

namespace ecsv::receiver {
    template<typename T>
    class Notifier {
    public:
        virtual void add(Subscriber<T>* subscriber) = 0;
        virtual void remove(Subscriber<T>* subscriber) = 0;
    protected:
        virtual void notify(const T& subject) = 0;
    };

}


#endif // PROCESORNOTIFIER_HPP_INCLUDED
