#include <catch2/catch.hpp>
#include <OnKiAlgo/arange.hpp>
#include <list>

TEST_CASE("arange with doubles", "[arange]")
{
    REQUIRE_THAT(onkialgo::arange(1.0, 4.0, 0.7), Catch::Matchers::Approx(std::vector<double>{ 1.0, 1.7, 2.4, 3.1, 3.8 }));
    REQUIRE_THAT(onkialgo::arange(1.0, 2.0, 0.2), Catch::Matchers::Approx(std::vector<double>{ 1.0, 1.2, 1.4, 1.6, 1.8, 2.0 }));
    REQUIRE_THAT(onkialgo::arange(1.0, 2.0, 0.19), Catch::Matchers::Approx(std::vector<double>{ 1.0, 1.19, 1.38, 1.57, 1.76, 1.95 }));
    REQUIRE_THAT(onkialgo::arange(1.0, 2.0, 6.19), Catch::Matchers::Approx(std::vector<double>{ 1.0 }));
}


TEST_CASE("arange with ints", "[arange]")
{
    REQUIRE_THAT(onkialgo::arange(1, 4, 1), Catch::Matchers::Approx(std::vector<int>{ 1, 2, 3, 4 }));
    REQUIRE_THAT(onkialgo::arange(1, 4, 5), Catch::Matchers::Approx(std::vector<int>{ 1 }));
}

TEST_CASE("arange with chrono::duration", "[arange]")
{
    using Seconds = std::chrono::duration<double>;
    using Milliseconds = std::chrono::duration<double, std::milli>;
    auto seconds_range = onkialgo::arange(Seconds{ 1 }, Seconds{ 2 }, Seconds{ 0.5 });
    REQUIRE_THAT(seconds_range, Catch::Matchers::Equals(std::vector<Seconds>{ Seconds{ 1 }, Seconds{ 1.5 }, Seconds{ 2 } }));
    auto seconds_range_alternative = onkialgo::arange<std::list<Milliseconds>, Seconds>(Seconds{ 1 }, Seconds{ 2 }, Milliseconds{ 500 });
    REQUIRE(std::is_same_v<decltype(seconds_range_alternative), std::list<Milliseconds>>);
    REQUIRE(std::equal(std::begin(seconds_range), std::end(seconds_range), std::begin(seconds_range_alternative), [](const auto &r1, const auto &r2) { return r1 == r2; }));
}