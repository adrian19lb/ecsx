#include <ComponentsManager.hpp>
#include <Subscriber.hpp>

namespace ecsx::component {

    bool ComponentsManager::checkIfEntityAlreadyExist(Entity entity) {
        if ( componentsMap.find(entity.id) != componentsMap.end() ) {
            return true;
        }else {
            return false;
        }
    }

    void ComponentsManager::add(receiver::Subscriber<Entity>* subscriber) {
        subscribers.emplace_back(subscriber)
    }

    void ComponentsManager::remove(receiver::Subscriber<Entity>* subscriber) {
    }

    void ComponentsManager::notify(const Entity& entity) {
        for (auto& i : subscribers) {
            i->subscribe(entity);
        }
    }
}
