#include <gmock/gmock.h>
#include <DatabaseSubscriber.hpp>

namespace ecsx::component::testing {
    template<typename T, typename R>
    class MockDatabaseSubscriber : public receiver::DatabaseSubscriber<T,R> {
    public:
     MockDatabaseSubscriber(R* database) {
         receiver::DatabaseSubscriber<T,R>::subscribedDatabase = database;
     }

     MOCK_METHOD1_T(subscribe, void(const T& subject));
    };
}
