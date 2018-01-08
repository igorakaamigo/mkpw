#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/application.hpp"

using ::testing::Return;

class MockApplication : public Amigo::Utils::Mkpw::Application {
public:
    MOCK_METHOD0(execute, int());
    MOCK_METHOD0(help, int());
};

TEST(Application, ItShouldCallExecuteAsADefaultAction) {
    MockApplication inst;

    EXPECT_CALL(inst, execute())
        .WillOnce(Return(123));

    auto result = inst.main(std::vector<std::string>());

    ASSERT_EQ(123, result);
}

TEST(Application, ItShouldReturnZeroForDefaultAction) {
    auto result = Amigo::Utils::Mkpw::Application::instance().main(
        std::vector<std::string>()
    );
    ASSERT_EQ(0, result);
}

TEST(Application, ItShouldCallHelpForAnyOtherAction) {
    MockApplication inst;

    EXPECT_CALL(inst, help())
        .WillOnce(Return(123));

    auto result = inst.main(std::vector<std::string>({ "anything" }));

    ASSERT_EQ(123, result);
}

TEST(Application, ItShouldReturnZeroForHelpAction) {
    auto result = Amigo::Utils::Mkpw::Application::instance().main(
        std::vector<std::string>({ "anything" })
    );
    ASSERT_EQ(0, result);
}
