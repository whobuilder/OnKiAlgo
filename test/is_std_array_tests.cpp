#include <catch2/catch.hpp>
#include <OnKiAlgo/is_std_array.hpp>

TEST_CASE("is_std_array test", "[is_std_array]")
{
    std::array<double, 5> arr;
    std::vector<double> vec;
    REQUIRE(onkialgo::is_std_array_v<decltype(arr)>);
    REQUIRE_FALSE(onkialgo::is_std_array_v<decltype(vec)>);
}

TEST_CASE("is_raw_or_std_array test", "[is_raw_or_std_array]")
{
    std::array<double, 5> arr;
    int carr[6];
    std::vector<double> vec;
    REQUIRE(onkialgo::is_raw_or_std_array_v<decltype(arr)>);
    REQUIRE(onkialgo::is_raw_or_std_array_v<decltype(carr)>);
    REQUIRE_FALSE(onkialgo::is_raw_or_std_array_v<decltype(vec)>);
}