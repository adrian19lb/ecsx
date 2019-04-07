#ifndef COMPONENT_HPP_INCLUDED
#define COMPONENT_HPP_INCLUDED

#include <BaseComponent.hpp>

namespace ecsx::component {

    template<typename ComponentType>
    struct Component : public BaseComponent {
        static ComponentId id;
    };

    template<typename ComponentType>
    ComponentId Component<ComponentType>::id = BaseComponent::baseId++;

}

#endif // COMPONENT_HPP_INCLUDED
