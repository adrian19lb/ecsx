#ifndef POSITIONCOMPONENT_HPP_INCLUDED
#define POSITIONCOMPONENT_HPP_INCLUDED

#include <Component.hpp>

namespace ecsx::component {

    struct PositionComponent : public Component<PositionComponent> {
    public:
        PositionComponent() = default;
        PositionComponent(float x, float y) {
            this->x = x;
            this->y = y;
        }

        float x = 0.f;
        float y = 0.f;
    };

}

#endif // POSITIONCOMPONENT_HPP_INCLUDED
