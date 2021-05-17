#include <catch2/catch.hpp>
#include <OnKiAlgo/slide.hpp>

TEST_CASE("slide standard test", "[slide]")
{
    const std::vector<double> vec{ 1, 2, 3, 4, 5 };
    std::size_t sliding_size = 3;
    std::vector<std::vector<double>> expected{ { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
    REQUIRE_THAT(onkialgo::slide<std::vector<std::vector<double>>>(vec, sliding_size), Catch::Matchers::Equals(expected));
}

TEST_CASE("slide test input container as array", "[slide]")
{
    std::array<int, 5> arr{ 1, 2, 3, 4, 5 };
    std::size_t sliding_size = 5;
    using OutputType = std::vector<std::vector<double>>;
    OutputType expected{ { 1, 2, 3, 4, 5 } };
    REQUIRE_THAT(onkialgo::slide<OutputType>(arr, sliding_size), Catch::Matchers::Equals(expected));
}

TEST_CASE("slide test inner container as array", "[slide]")
{
    std::vector<int> vec{ 1, 2, 3 };
    std::size_t sliding_size = 2;
    using OutputType = std::vector<std::array<int, 2>>;
    OutputType expected{ { 1, 2 }, { 2, 3 } };
    REQUIRE_THAT(onkialgo::slide<OutputType>(vec, sliding_size), Catch::Matchers::Equals(expected));
}