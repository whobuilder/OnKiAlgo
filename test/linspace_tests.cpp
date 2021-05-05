#include <catch2/catch.hpp>
#include <OnKiAlgo/linspace.hpp>
#include <chrono>

TEST_CASE("linspace with doubles", "[linspace]")
{
    REQUIRE_THAT(onkialgo::linspace(1.0, 4.0, 7), Catch::Matchers::Equals(std::vector<double>{ 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 }));
    REQUIRE_THAT(onkialgo::linspace(1.0, 4.0, 4, false), Catch::Matchers::Equals(std::vector<double>{ 1.0, 1.75, 2.5, 3.25 }));
}

TEST_CASE("linspace with ints", "[linspace]")
{
    REQUIRE_THAT(onkialgo::linspace<int>(-1, 1, 3), Catch::Matchers::Equals(std::vector<int>{ -1, 0, 1 }));
    REQUIRE_THAT(onkialgo::linspace<int>(-1, 1, 2, false), Catch::Matchers::Equals(std::vector<int>{ -1, 0 }));
}

TEST_CASE("linspace with chrono", "[linspace]")
{
    REQUIRE_THAT(onkialgo::linspace(std::chrono::seconds{ 2 }, std::chrono::seconds{ 4 }, 3),
      Catch::Matchers::Equals(std::vector<std::chrono::seconds>{
        std::chrono::seconds{ 2 }, std::chrono::seconds{ 3 }, std::chrono::seconds{ 4 } }));
}

TEST_CASE("linspace with chrono duration", "[linspace]")
{
    using Seconds = std::chrono::duration<double>;
    REQUIRE_THAT(onkialgo::linspace(Seconds{ 2 }, Seconds{ 4 }, 5),
      Catch::Matchers::Equals(std::vector<Seconds>{
        Seconds{ 2 }, Seconds{ 2.5 }, Seconds{ 3.0 }, Seconds{ 3.5 }, Seconds{ 4 } }));
}

TEST_CASE("linspace too big step", "[linspace]")
{
    REQUIRE_THAT(onkialgo::linspace<int>(1, 2, 3), Catch::Matchers::Equals(std::vector<int>{1}));
}
