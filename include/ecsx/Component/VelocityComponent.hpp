#ifndef MOVECOMPONENT_HPP_INCLUDED
#define MOVECOMPONENT_HPP_INCLUDED

#include <Component.hpp>

namespace ecsx::component {

    struct VelocityComponent : public Component<VelocityComponent> {
    public:
        VelocityComponent() = default;
        VelocityComponent(float x, float y) {
                this->x = x;
                this->y = y;
            }
         
        float x = 100.f;
        float y = 100.f;
     };
}


#endif // MOVECOMPONENT_HPP_INCLUDED
