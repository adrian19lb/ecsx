#include <utility>

namespace ecsx::component {

    template<typename ComponentType, typename... TArg> void ComponentsHolder::attach(TArg... arg) {
        check<ComponentType>();
        auto newComponent = std::make_unique<ComponentType>( std::forward<TArg>(arg)... ) ;
        componentsArray[ComponentType::id] = std::move(newComponent);
    }

    template<typename ComponentType>
    void ComponentsHolder::check() {
        checkIfIsBaseOf<ComponentType>();
        checkIfValueIsLessThanArraySize(ComponentType::id);
    }

    template<typename ComponentType> void ComponentsHolder::checkIfIsBaseOf() {
        static_assert( std::is_base_of< Component<ComponentType>, ComponentType>::value,
                       "ComponentType must be derived from Component struct");

    }

    template<typename ComponentType> void ComponentsHolder::detach() {
        check<ComponentType>();
        componentsArray[ComponentType::id].reset();
    }

    template<typename ComponentType> ComponentType& ComponentsHolder::get() {
        check<ComponentType>();
        auto componentToReturn = componentsArray[ComponentType::id].get();

        return getComponentAfterNullValdiation<ComponentType>(componentToReturn);
    }

    template<typename ComponentType> ComponentType& ComponentsHolder::getComponentAfterNullValdiation(BaseComponent* component) {
        if (component) {
            return *static_cast<ComponentType*>(component);
        }else {
            throw std::logic_error("Error - attempt to acces null component");
        }
    }
}
