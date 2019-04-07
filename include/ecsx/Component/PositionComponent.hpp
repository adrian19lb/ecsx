#ifndef POSITIONCOMPONENT_HPP_INCLUDED
#define POSITIONCOMPONENT_HPP_INCLUDED

#include <Component.hpp>

namespace ecsx::component {

    struct PositionComponent : public Component<PositionComponent> {
        float x = 0.f;
        float y = 0.f;
    };

}

#endif // POSITIONCOMPONENT_HPP_INCLUDED
