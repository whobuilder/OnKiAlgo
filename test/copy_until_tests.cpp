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
    const TestType v{ 1, 2, 3, 4, 5 };
    using OutputType = std::array<typename TestType::value_type, 4>;
    OutputType expected{ 1, 2, 3, 4 };
    auto v_copy = onkialgo::copy_until<OutputType>(v, [](const auto &value) { return value == 5; });
    auto v_copy_default_type = onkialgo::copy_until(v, [](const auto &value) { return value == 5; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
    REQUIRE(std::is_same_v<decltype(v_copy), OutputType>);
    REQUIRE(std::equal(std::begin(v_copy_default_type), std::end(v_copy_default_type), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
    REQUIRE(std::is_same_v<decltype(v_copy_default_type), TestType>);
}

TEMPLATE_PRODUCT_TEST_CASE("copy until binary predicate test", "[copy_until]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    const TestType v{ 1, 2, 3, 4, 5 };
    TestType v2{ 2, 4, 6, 8, 10 };
    using OutputType = std::array<typename TestType::value_type, 4>;
    OutputType expected{ 1, 2, 3, 4 };

    auto v_copy = onkialgo::copy_until<OutputType>(v, v2, [](const auto &value1, const auto &value2) { return value1 + value2 == 15; });
    auto v_copy_default_type = onkialgo::copy_until(v, v2, [](const auto &value1, const auto &value2) { return value1 + value2 == 15; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
    REQUIRE(std::is_same_v<decltype(v_copy), OutputType>);
    REQUIRE(std::equal(std::begin(v_copy_default_type), std::end(v_copy_default_type), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
    REQUIRE(std::is_same_v<decltype(v_copy_default_type), TestType>);
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
TEMPLATE_TEST_CASE("copy until binary predicate test with std::array", "[copy_until]", (std::array<double, 5>), (std::array<int, 5>))
{
    TestType v{ 1, 2, 3, 4, 5 };
    TestType v2{ 2, 4, 6, 8, 10 };
    using OutputType = std::array<typename TestType::value_type, 4>;
    OutputType expected{ 1, 2, 3, 4 };
    auto v_copy = onkialgo::copy_until<OutputType>(v, v2, [](const auto &value1, const auto &value2) { return value1 + value2 == 15; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
}

TEMPLATE_TEST_CASE("copy until test with std::array", "[copy_until]", (std::array<double, 5>), (std::array<int, 5>))
{
    TestType v{ 1, 2, 3, 4, 5 };
    using OutputType = std::array<typename TestType::value_type, 4>;
    OutputType expected{ 1, 2, 3, 4 };
    auto v_copy = onkialgo::copy_until<OutputType>(v, [](const auto &value) { return value == 5; });
    REQUIRE(std::equal(std::begin(v_copy), std::end(v_copy), std::begin(expected), [](const auto &value, const auto &e) { return value == Approx(e); }));
}