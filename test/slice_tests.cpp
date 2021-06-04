#include <catch2/catch.hpp>
#include <OnKiAlgo/slice.hpp>

TEMPLATE_TEST_CASE("slice test", "[slice]", std::vector<double>, (double[5]))
{
    const TestType range = { 1, 2, 3, 4, 5 };
    REQUIRE_THAT(onkialgo::slice<std::vector<double>>(range, 2, 4), Catch::Matchers::Equals(std::vector<double>{ 3, 4 }));
}