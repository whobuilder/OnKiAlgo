#include <catch2/catch.hpp>
#include <OnKiAlgo/distribution.hpp>
// #include <catch2/matchers/catch_matchers_generic.hpp>

TEST_CASE("uniform double distribution", "[random_uniform_distribution]")
{
    double start = 2.0;
    double end = 5.0;
    std::size_t num = 5;
    auto r = onkialgo::random_uniform_distribution(start, end, num);
    REQUIRE(r.size() == num);
    REQUIRE_THAT(r, Catch::Matchers::Predicate<std::vector<double>>([&](const std::vector<double> &range) -> bool {
        for (const auto &val : range) {
            if ((val > end) || (val < start)) return false;
        }
        return true;
    },
                      "The elements of the vector are in expected range"));
}

TEST_CASE("uniform int distribution", "[random_uniform_distribution]")
{
    int start = 2;
    int end = 5;
    std::size_t num = 6;
    auto r = onkialgo::random_uniform_distribution(start, end, num);
    REQUIRE(r.size() == num);
    REQUIRE_THAT(r, Catch::Matchers::Predicate<std::vector<int>>([&](const std::vector<int> &range) -> bool {
        for (const auto &val : range) {
            if ((val > end) || (val < start)) return false;
        }
        return true;
    },
                      "The elements of the vector are in expected range"));
}