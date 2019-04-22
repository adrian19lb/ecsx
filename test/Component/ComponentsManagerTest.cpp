#include <gtest/gtest.h>
#include <ComponentsManager.hpp>
#include <PositionComponent.hpp>
#include <MockDatabaseSubscriber.hpp>

namespace ecsx::component::testing {

    TEST(ComponentsManagerTest, attachTest) {
        ComponentsManager testedComponentsManager;
        Entity dummyEntity;

        testedComponentsManager.attach<PositionComponent>(dummyEntity);
        PositionComponent& positionComponent = testedComponentsManager.get<PositionComponent>(dummyEntity);

        ASSERT_EQ(positionComponent.x, 0.f);
        ASSERT_EQ(positionComponent.y, 0.f);
    }

    TEST(ComponentsManagerTest, detachTest) {
        ComponentsManager testedComponentsManager;
        Entity dummyEntity;

        testedComponentsManager.attach<PositionComponent>(dummyEntity);
        testedComponentsManager.detach<PositionComponent>(dummyEntity);

        ASSERT_THROW( testedComponentsManager.get<PositionComponent>(dummyEntity), std::out_of_range );
    }

    TEST(ComponentsManagerTest, notifyTest) {
        ComponentsManager testedComponentsManager;
        Entity dummyEntity;
        MockDatabaseSubscriber<Entity, ComponentsManager> subscriber(&testedComponentsManager);
        EXPECT_CALL(subscriber, subscribe(dummyEntity))
            .Times(2);

        testedComponentsManager.add(&subscriber);
        testedComponentsManager.attach<PositionComponent>(dummyEntity);
        testedComponentsManager.detach<PositionComponent>(dummyEntity);
    }

    TEST(ComponentsManagerTest, removeTest) {
        ComponentsManager testedComponentsManager;
        Entity dummyEntity;
        MockDatabaseSubscriber<Entity, ComponentsManager> subscriber(&testedComponentsManager);

        EXPECT_CALL(subscriber, subscribe(dummyEntity))
            .Times(1);

        testedComponentsManager.add(&subscriber);
        testedComponentsManager.attach<PositionComponent>(dummyEntity);
        testedComponentsManager.remove(&subscriber);
        testedComponentsManager.detach<PositionComponent>(dummyEntity);
    }
}
