#include <catch2/catch.hpp>
#include <OnKiAlgo/distribution.hpp>

TEMPLATE_TEST_CASE("random uniform distribution", "[random_uniform_distribution]", double, int)
{
    TestType start = 2;
    TestType end = 5;
    std::size_t num = 5;
    auto r = onkialgo::random_uniform_distribution(start, end, num);
    REQUIRE(r.size() == num);
    REQUIRE_THAT(r, Catch::Matchers::Predicate<std::vector<TestType>>([&](const std::vector<TestType> &range) -> bool {
        for (const auto &val : range) {
            if ((val > end) || (val < start)) return false;
        }
        return true;
    },
                      "The elements of the vector are in expected range"));
}