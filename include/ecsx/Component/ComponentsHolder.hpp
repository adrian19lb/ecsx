#ifndef COMPONENTSHOLDER_HPP_INCLUDED
#define COMPONENTSHOLDER_HPP_INCLUDED

#include <Component.hpp>
#include <memory>

namespace ecsx::component {

    class ComponentsHolder {
    public:
        ComponentsHolder() = default;
        ComponentsHolder(ComponentsHolder&& x) = default;
    private:
        static const int MAX_COMPONENTS_NUMBER = 64;
    public:
        template<typename ComponentType, typename... TArg> void attach(TArg... args);
    private:
        template<typename ComponentType> void check();
        template<typename ComponentType> void checkIfIsBaseOf();
        void checkIfValueIsLessThanArraySize(ComponentId id);
    public:
        template<typename ComponentType> void detach();
        template<typename ComponentType> ComponentType& get();
    private:
        template<typename ComponentType> ComponentType& getComponentAfterNullValdiation(BaseComponent* component);
    private:
        BaseComponentPtr componentsArray[MAX_COMPONENTS_NUMBER];
    };

    using ComponentsHolderPtr = std::unique_ptr<ComponentsHolder>;
}

#include <ComponentsHolder.inl>

#endif // COMPONENTSHOLDER_HPP_INCLUDED
