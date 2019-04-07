#ifndef PROCESORNOTIFIER_HPP_INCLUDED
#define PROCESORNOTIFIER_HPP_INCLUDED

namespace ecsx::receiver {
    
    template<typename T>
    class Subscriber;
   
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
