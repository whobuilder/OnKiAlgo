#include <catch2/catch.hpp>
#include <OnKiAlgo/generic_helpers.hpp>

TEST_CASE("vector with size", "[initialize_with_size]")
{
    auto vec = onkialgo::initialize_with_size(std::vector<int>{}, 6);
    REQUIRE(vec.size() == 6);
}


TEST_CASE("array with size", "[initialize_with_size]")
{
    auto arr = onkialgo::initialize_with_size(std::array<int, 6>{}, 6);
    static_assert(arr.size() == 6);
    REQUIRE(arr.size() == 6);
}

TEST_CASE("rvalue vector with one less size", "[container_with_one_less_size]")
{
    auto vec = onkialgo::container_with_size_increased_by<-1>(std::vector<int>(6));
    REQUIRE(vec.size() == 5);
}

TEST_CASE("lvalue vector with one less size", "[container_with_one_less_size]")
{
    const auto &big_vec = std::vector<int>(6);
    auto vec = onkialgo::container_with_size_increased_by<-1>(big_vec);
    REQUIRE(vec.size() == 5);
}

TEST_CASE("lvalue array with one less size", "[container_with_one_less_size]")
{
    auto big_array = std::array<int, 6>{};
    auto arr = onkialgo::container_with_size_increased_by<-1>(big_array);
    static_assert(arr.size() == 5);
    REQUIRE(arr.size() == 5);
}

TEST_CASE("rvalue array with one less size", "[container_with_one_less_size]")
{
    auto arr = onkialgo::container_with_size_increased_by<-1>(std::array<int, 6>{});
    static_assert(arr.size() == 5);
    REQUIRE(arr.size() == 5);
}