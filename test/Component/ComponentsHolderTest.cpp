#include <gtest/gtest.h>
#include <ComponentsHolder.hpp>
#include <PositionComponent.hpp>

namespace ecsx::component::testing {

    TEST(ComponentsHolderTest, attachComponentTest) {
        ComponentsHolder testedComponentsHolder;
        testedComponentsHolder.attach<PositionComponent>(100.f, 200.f);
        PositionComponent& component = testedComponentsHolder.get<PositionComponent>();

        ASSERT_EQ(component.x, 100.f);
        ASSERT_EQ(component.y, 200.f);
    }

    TEST(ComponentsHolderTest, detachComponentTest) {
        ComponentsHolder testedComponentsHolder;
        testedComponentsHolder.attach<PositionComponent>();
        testedComponentsHolder.detach<PositionComponent>();

        ASSERT_THROW( testedComponentsHolder.get<PositionComponent>(), std::logic_error );
    }

}
