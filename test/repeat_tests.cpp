#include <catch2/catch.hpp>
#include <OnKiAlgo/repeat.hpp>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <fmt/format.h>
#include <fmt/ranges.h>

TEMPLATE_PRODUCT_TEST_CASE("repeat with standard containers", "[repeat]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    TestType input = { 1, 2, 3, 4 };
    std::array<typename TestType::value_type, 8> expected_values = { 1, 1, 2, 2, 3, 3, 4, 4 };
    TestType output(std::size(expected_values));
    onkialgo::repeat(std::begin(input), std::end(input), std::begin(output), 2);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_PRODUCT_TEST_CASE("repeat_n_times with standard containers", "[repeat]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    TestType input = { 1, 2, 3, 4 };
    auto n_generator = [](const auto &v) { return v; };
    std::array<typename TestType::value_type, 10> expected_values = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
    TestType output(std::size(expected_values));
    onkialgo::repeat_n_times(std::begin(input), std::end(input), std::begin(output), n_generator);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_PRODUCT_TEST_CASE("repeat_n_times using binary n generator with standard containers", "[repeat]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    TestType input1 = { 1, 2, 3, 4 };
    TestType input2 = { 0, 1, 2, 3 };
    auto n_generator = [](const auto &first, const auto &second) { return first + second; };
    std::array<typename TestType::value_type, 16> expected_values = { 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4 };
    TestType output(std::size(expected_values));
    onkialgo::repeat_n_times(std::begin(input1), std::end(input1), std::begin(input2), std::begin(output), n_generator);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_TEST_CASE("repeat with std::array", "[repeat]", (std::array<int, 4>), (std::array<double, 4>))
{
    TestType input = { 1, 2, 3, 4 };
    std::array<typename TestType::value_type, 8> expected_values = { 1, 1, 2, 2, 3, 3, 4, 4 };
    std::array<typename TestType::value_type, 8> output;
    onkialgo::repeat(std::begin(input), std::end(input), std::begin(output), 2);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_TEST_CASE("repeat_n_times with std::array", "[repeat]", (std::array<int, 4>), (std::array<double, 4>))
{
    TestType input = { 1, 2, 3, 4 };
    auto n_generator = [](const auto &v) { return v; };
    std::array<typename TestType::value_type, 10> expected_values = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
    std::array<typename TestType::value_type, 10> output;
    onkialgo::repeat_n_times(std::begin(input), std::end(input), std::begin(output), n_generator);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_TEST_CASE("repeat_n_times using binary n generator with std::array", "[repeat]", (std::array<int, 4>), (std::array<double, 4>))
{
    TestType input1 = { 1, 2, 3, 4 };
    TestType input2 = { 0, 1, 2, 3 };
    auto n_generator = [](const auto &first, const auto &second) { return first + second; };
    std::array<typename TestType::value_type, 16> expected_values = { 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4 };
    std::array<typename TestType::value_type, 16> output;
    onkialgo::repeat_n_times(std::begin(input1), std::end(input1), std::begin(input2), std::begin(output), n_generator);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}