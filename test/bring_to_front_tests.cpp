#include <catch2/catch.hpp>
#include <OnKiAlgo/bring_to_front.hpp>
#include <vector>
#include <algorithm>

TEST_CASE("bring to front standard test", "[bring_to_front]")
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 2, 3, 2 };
    int front_value = 2;
    auto it = onkialgo::bring_to_front(vec, front_value);
    REQUIRE(*it != front_value);
    REQUIRE(std::all_of(begin(vec), it, [front_value](const auto &val) { return val == front_value; }));
}


TEST_CASE("bring to front non existing value", "[bring_to_front]")
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 2, 3, 2 };
    int front_value = 42;
    auto it = onkialgo::bring_to_front(vec, front_value);
    REQUIRE(it == begin(vec));
}

TEST_CASE("bring to front if standard test", "[bring_to_front, bring_to_front_if]")
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 2, 3, 2 };
    int front_value = 2;
    auto it = onkialgo::bring_to_front_if(vec, [front_value](int value) { return value == front_value; });
    REQUIRE(*it != front_value);
    REQUIRE(std::all_of(begin(vec), it, [front_value](const auto &val) { return val == front_value; }));
}

TEST_CASE("bring to front if non existing value", "[bring_to_front, bring_to_front_if]")
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 2, 3, 2 };
    int front_value = 42;
    auto it = onkialgo::bring_to_front_if(vec, [front_value](int value) { return value == front_value; });
    REQUIRE(it == begin(vec));
}