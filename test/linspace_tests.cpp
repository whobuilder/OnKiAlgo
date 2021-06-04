#include <catch2/catch.hpp>
#include <OnKiAlgo/linspace.hpp>
#include <chrono>

TEMPLATE_TEST_CASE("linspace test", "[linspace]", int, double, std::chrono::seconds, std::chrono::duration<double>)
{
    auto start = TestType{ 1 };
    auto end = TestType{ 5 };
    std::size_t num = 4;
    REQUIRE_THAT(onkialgo::linspace(start, end, num, false), Catch::Matchers::Equals(std::vector<TestType>{ TestType{ 1 }, TestType{ 2 }, TestType{ 3 }, TestType{ 4 } }));
}

TEST_CASE("linspace too big step", "[linspace]")
{
    REQUIRE_THAT(onkialgo::linspace(1, 2, 3), Catch::Matchers::Equals(std::vector<int>{ 1 }));
}
