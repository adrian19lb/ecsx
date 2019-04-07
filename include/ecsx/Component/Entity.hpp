#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <Bitset.hpp>
#include <set>

namespace ecsx::component {

    using EntityId = int long;
    const size_t COMPONENTS_NUMBER = 64;

    inline EntityId counter() {
        static EntityId id = 0;
        EntityId nextId = id++;

        return nextId;
    }

    class ComponentsManager;
    struct Entity {
        friend ComponentsManager;

        ~Entity();
        const EntityId id = counter();
        bool isAwake = true;

        bool operator<(const Entity& entity) const;
        bool operator==(const Entity& entity) const;
        const Bitset<COMPONENTS_NUMBER>& getComponents() const;
    private:
        Bitset<COMPONENTS_NUMBER> componentsBitset;
    };

    using EntityUniqueList = std::set<Entity>;
}

#endif // ENTITY_HPP_INCLUDED
