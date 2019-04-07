#ifndef COMPONENTSMANAGER_HPP_INCLUDED
#define COMPONENTSMANAGER_HPP_INCLUDED

#include <vector>
#include <unordered_map>
#include <ComponentsHolder.hpp>
#include <Entity.hpp>
#include <Notifier.hpp>

namespace  ecsx::receiver {
    template<typename T>
    class Subscriber;
}

namespace ecsx::component {
    
    class ComponentsManager : public receiver::Notifier<Entity> {
    public:
        template<typename ComponentType> Entity& attach(Entity& entity);
    private:
        bool checkIfEntityAlreadyExist(Entity entity);
        template<typename ComponentType> void attachComponentToEntity(const Entity& entity);
    public:
        template<typename ComponentType> ComponentType& get(const Entity& entity);
        template<typename ComponentType> void detach(Entity& entity);
        void add(receiver::Subscriber<Entity>* subscriber) override;
        void remove(receiver::Subscriber<Entity>* subscriber) override;
    private:
        void notify(const Entity& entity) override;
        template<typename ComponentType> void detachComponentFromEntity(const Entity& entity);
    private:
        std::unordered_map<EntityId, ComponentsHolderPtr> componentsMap;
        std::vector< receiver::Subscriber<Entity>* > subscribers;
    };

}

#include <ComponentsManager.inl>
#endif // COMPONENTSMANAGER_HPP_INCLUDED
