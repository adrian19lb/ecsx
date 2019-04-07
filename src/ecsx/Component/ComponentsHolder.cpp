#include <ComponentsHolder.hpp>

namespace ecsx::component {

    void ComponentsHolder::checkIfValueIsLessThanArraySize(ComponentId id) {
        if (id > MAX_COMPONENTS_NUMBER) {
            throw std::out_of_range("Given ComponentType::id is greater than holder size!\n");
        }
    }

}
