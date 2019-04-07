#include <Entity.hpp>

namespace ecsx::component {

    Entity::~Entity() {

    }

    bool Entity::operator<(const Entity& entity) const {
        return id < entity.id;
    }

    bool Entity::operator==(const Entity& entity) const {
        return this->id == entity.id;
    }

    const Bitset<COMPONENTS_NUMBER>& Entity::getComponents() const {
        return componentsBitset;
    }

}
