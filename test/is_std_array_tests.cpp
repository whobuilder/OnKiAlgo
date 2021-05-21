#include <catch2/catch.hpp>
#include <OnKiAlgo/is_std_array.hpp>

TEST_CASE("is_std_array test", "[is_std_array]")
{
    std::array<double, 5> arr;
    std::vector<double> vec;
    REQUIRE(onkialgo::is_std_array_v<decltype(arr)>);
    REQUIRE_FALSE(onkialgo::is_std_array_v<decltype(vec)>);
}