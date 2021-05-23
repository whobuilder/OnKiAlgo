#include <catch2/catch.hpp>
#include <OnKiAlgo/slice.hpp>

TEST_CASE("slice standard test", "[slice]")
{
    const std::vector<double> vec{ 1, 2, 3, 4, 5 };
    REQUIRE_THAT(onkialgo::slice<std::vector<double>>(vec, 2, 4), Catch::Matchers::Equals(std::vector<double>{ 3, 4 }));
}

TEST_CASE("raw array slice test", "[slice]")
{
    const double carray[5] = { 1, 2, 3, 4, 5 };
    REQUIRE_THAT(onkialgo::slice<std::vector<double>>(carray, 2, 4), Catch::Matchers::Equals(std::vector<double>{ 3, 4 }));
}