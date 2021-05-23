#include <catch2/catch.hpp>
#include <OnKiAlgo/container_factory.hpp>

TEST_CASE("create vector with size", "[initialize_with_size]")
{
    auto vec = onkialgo::ContainerFactory<std::vector<int>>::create(6);
    REQUIRE(vec.size() == 6);
}


TEST_CASE("array with size", "[initialize_with_size]")
{
    auto arr = onkialgo::ContainerFactory<std::array<int, 6>>::create(6);
    static_assert(arr.size() == 6);
    REQUIRE(arr.size() == 6);
}

TEST_CASE("rvalue vector with one less size", "[container_with_one_less_size]")
{
    auto vec = onkialgo::ContainerFactory<std::vector<int>>::create_with_incremented_size<-1>(std::vector<int>(6));
    REQUIRE(vec.size() == 5);
}

TEST_CASE("lvalue ref vector with one less size", "[container_with_one_less_size]")
{
    const auto &big_vec = std::vector<int>(6);
    auto vec = onkialgo::ContainerFactory<std::vector<int>>::create_with_incremented_size<-1>(big_vec);
    REQUIRE(vec.size() == 5);
}

TEST_CASE("lvalue array with decreased size by 2", "[container_with_one_less_size]")
{
    const auto &big_array = std::array<int, 6>{};
    auto arr = onkialgo::ContainerFactory<std::array<int, 6>>::create_with_incremented_size<-2>(big_array);
    REQUIRE(std::is_same_v<std::array<int, 4>, decltype(arr)>);
}

TEST_CASE("rvalue array with increased size by 3", "[container_with_one_less_size]")
{
    auto arr = onkialgo::ContainerFactory<std::array<int, 6>>::create_with_incremented_size<3>(std::array<int, 6>{});
    REQUIRE(std::is_same_v<std::array<int, 9>, decltype(arr)>);
}