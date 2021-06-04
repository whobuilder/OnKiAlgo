#include <catch2/catch.hpp>
#include <OnKiAlgo/slide.hpp>

TEMPLATE_TEST_CASE("slide test", "[slide]", std::vector<double>, (std::array<double, 5>), (double[5]))
{
    TestType range = { 1, 2, 3, 4, 5 };
    int sliding_size = 3;
    std::vector<std::vector<double>> expected{ { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
    REQUIRE_THAT(onkialgo::slide<std::vector<std::vector<double>>>(range, sliding_size), Catch::Matchers::Equals(expected));
}

TEST_CASE("slide test inner container as array", "[slide]")
{
    std::vector<int> vec{ 1, 2, 3 };
    int sliding_size = 2;
    using OutputType = std::vector<std::array<int, 2>>;
    OutputType expected{ { 1, 2 }, { 2, 3 } };
    REQUIRE_THAT(onkialgo::slide<OutputType>(vec, sliding_size), Catch::Matchers::Equals(expected));
}