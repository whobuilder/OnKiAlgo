#include <catch2/catch.hpp>
#include <OnKiAlgo/copy_until.hpp>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif
TEMPLATE_PRODUCT_TEST_CASE("copy until test", "[copy_until]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    TestType v{ 1, 2, 3, 4, 5 };
    std::array<typename TestType::value_type, 4> expected{ 1, 2, 3, 4 };
    TestType v_copy(std::size(expected));
    onkialgo::copy_until(begin(v), end(v), std::begin(v_copy), [](const auto &value) { return value == 5; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
}

TEMPLATE_PRODUCT_TEST_CASE("copy until binary predicate test", "[copy_until]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    TestType v{ 1, 2, 3, 4, 5 };
    TestType v2{ 2, 4, 6, 8, 10 };
    std::array<typename TestType::value_type, 4> expected{ 1, 2, 3, 4 };
    TestType v_copy(std::size(expected));
    onkialgo::copy_until(begin(v), end(v), begin(v2), std::begin(v_copy), [](const auto &value1, const auto &value2) { return value1 + value2 == 15; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
TEMPLATE_TEST_CASE("copy until binary predicate test with std::array", "[copy_until]", (std::array<double, 5>), (std::array<int, 5>))
{
    TestType v{ 1, 2, 3, 4, 5 };
    TestType v2{ 2, 4, 6, 8, 10 };
    std::array<typename TestType::value_type, 4> expected{ 1, 2, 3, 4 };
    std::array<typename TestType::value_type, 4> v_copy;
    onkialgo::copy_until(begin(v), end(v), begin(v2), std::begin(v_copy), [](const auto &value1, const auto &value2) { return value1 + value2 == 15; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
}

TEMPLATE_TEST_CASE("copy until test with std::array", "[copy_until]", (std::array<double, 5>), (std::array<int, 5>))
{
    TestType v{ 1, 2, 3, 4, 5 };
    std::array<typename TestType::value_type, 4> expected{ 1, 2, 3, 4 };
    std::array<typename TestType::value_type, 4> v_copy;
    onkialgo::copy_until(begin(v), end(v), std::begin(v_copy), [](const auto &value) { return value == 5; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
}