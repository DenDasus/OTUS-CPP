//
// Created by Denis on 12.08.2019.
//

#include "gtest/gtest.h"
#include "Utils.h"
#include <vector>

TEST(Utils_test, split_1) {
    std::vector<std::string> result = Utils::split("192.168.0.1", '.');
    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result.at(0), "192");
    ASSERT_EQ(result.at(1), "168");
    ASSERT_EQ(result.at(2), "0");
    ASSERT_EQ(result.at(3), "1");
}

TEST(Utils_test, split_2) {
    std::vector<std::string> result = Utils::split("", '.');
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.at(0), "");
}

TEST(Utils_test, split_3) {
    std::vector<std::string> result = Utils::split("11", '.');
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.at(0), "11");
}

TEST(Utils_test, split_4) {
    std::vector<std::string> result = Utils::split("..", '.');
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result.at(0), "");
    ASSERT_EQ(result.at(1), "");
    ASSERT_EQ(result.at(2), "");
}

TEST(Utils_test, split_5) {
    std::vector<std::string> result = Utils::split("11.", '.');
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(result.at(0), "11");
    ASSERT_EQ(result.at(1), "");
}

TEST(Utils_test, split_6) {
    std::vector<std::string> result = Utils::split(".11", '.');
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(result.at(0), "");
    ASSERT_EQ(result.at(1), "11");
}

TEST(Utils_test, split_7) {
    std::vector<std::string> result = Utils::split("11.22", '.');
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(result.at(0), "11");
    ASSERT_EQ(result.at(1), "22");
}
