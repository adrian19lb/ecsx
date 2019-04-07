namespace ecsx::component {

    template<typename ComponentType> Entity& ComponentsManager::attach(Entity& entity) {
        auto componentId = ComponentType::id;
        entity.componentsBitset[componentId]= true;
        attachComponentToEntity<ComponentType>(entity);
        notify(entity);
    }

    template<typename ComponentType> void ComponentsManager::attachComponentToEntity(const Entity& entity) {
        if ( checkIfEntityAlreadyExist(entity) ) {
            auto& entityComponents = componentsMap.at(entity.id);
            entityComponents->attach<ComponentType>();
        }else {
            auto newEntityComponents = std::make_unique<ComponentsHolder>();
            newEntityComponents->attach<ComponentType>();
            componentsMap.emplace( std::make_pair(entity.id, std::move(newEntityComponents)) );
        }
    }

    template<typename ComponentType> ComponentType& ComponentsManager::get(const Entity& entity) {
        auto& entityAttachedComponents = *componentsMap.at(entity.id);

        return entityAttachedComponents.get<ComponentType>();
    }

    template<typename ComponentType> void ComponentsManager::detach(Entity& entity) {
        auto componentId = ComponentType::id;
        entity.componentsBitset[componentId]= false;
        detachComponentFromEntity<ComponentType>(entity);
        notify(entity);
    }

    template<typename ComponentType> void ComponentsManager::detachComponentFromEntity(const Entity& entity) {
        for (auto itr = componentsMap.begin(); itr != componentsMap.end(); ++itr) {
            if (itr->first == entity.id) {
                itr = componentsMap.erase(itr);
                break;
            }
        }
    }
}
