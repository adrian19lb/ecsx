#ifndef BASECOMPONENT_HPP_INCLUDED
#define BASECOMPONENT_HPP_INCLUDED

#include <memory>

namespace ecsx::component {

    using ComponentId = long int;

    struct BaseComponent {
    protected:
        static ComponentId baseId;
    };

    using BaseComponentPtr = std::unique_ptr<BaseComponent>;

}

#endif // BASECOMPONENT_HPP_INCLUDED
