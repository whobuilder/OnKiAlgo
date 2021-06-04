#include <catch2/catch.hpp>
#include <OnKiAlgo/repeat.hpp>
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
TEMPLATE_PRODUCT_TEST_CASE("repeat with standard containers", "[repeat]", (std::vector, std::list, std::deque), (double, int))
{
    TestType input = { 1, 2, 3, 4 };
    using OutputType = std::array<typename TestType::value_type, 8>;
    OutputType expected_values = { 1, 1, 2, 2, 3, 3, 4, 4 };
    auto output = onkialgo::repeat<OutputType>(input, 2);
    REQUIRE(std::is_same_v<decltype(output), OutputType>);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
    auto output_with_default_type = onkialgo::repeat(input, 2);
    REQUIRE(std::is_same_v<decltype(output_with_default_type), TestType>);
    REQUIRE(std::equal(std::begin(output_with_default_type), std::end(output_with_default_type), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_PRODUCT_TEST_CASE("repeat_n_times with standard containers", "[repeat]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    TestType input = { 1, 2, 3, 4 };
    using OutputType = std::array<typename TestType::value_type, 10>;
    auto n_generator = [](const auto &v) { return v; };
    OutputType expected_values = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
    auto output = onkialgo::repeat_n_times<OutputType>(input, n_generator);
    REQUIRE(std::is_same_v<decltype(output), OutputType>);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
    auto output_with_default_type = onkialgo::repeat_n_times(input, n_generator);
    REQUIRE(std::is_same_v<decltype(output_with_default_type), TestType>);
    REQUIRE(std::equal(std::begin(output_with_default_type), std::end(output_with_default_type), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_PRODUCT_TEST_CASE("repeat_n_times using binary n generator with standard containers", "[repeat]", (std::vector, std::list, std::deque, std::forward_list), (double, int))
{
    TestType input1 = { 1, 2, 3, 4 };
    TestType input2 = { 0, 1, 2, 3 };
    using OutputType = std::array<typename TestType::value_type, 16>;
    auto n_generator = [](const auto &first, const auto &second) { return first + second; };
    OutputType expected_values = { 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4 };
    auto output = onkialgo::repeat_n_times<OutputType>(input1, input2, n_generator);
    REQUIRE(std::is_same_v<decltype(output), OutputType>);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));

    auto output_with_default_type = onkialgo::repeat_n_times(input1, input2, n_generator);
    REQUIRE(std::is_same_v<decltype(output_with_default_type), TestType>);
    REQUIRE(std::equal(std::begin(output_with_default_type), std::end(output_with_default_type), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
TEMPLATE_TEST_CASE("repeat with std::array", "[repeat]", (std::array<int, 4>), (std::array<double, 4>))
{
    TestType input = { 1, 2, 3, 4 };
    using OutputType = std::array<typename TestType::value_type, 8>;
    OutputType expected_values = { 1, 1, 2, 2, 3, 3, 4, 4 };
    auto output = onkialgo::repeat<OutputType>(input, 2);
    REQUIRE(std::is_same_v<decltype(output), OutputType>);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
    auto output_with_default_type = onkialgo::repeat(input, 2);
    REQUIRE(std::is_same_v<decltype(output_with_default_type), std::vector<typename TestType::value_type>>);
    REQUIRE(std::equal(std::begin(output_with_default_type), std::end(output_with_default_type), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_TEST_CASE("repeat_n_times with std::array", "[repeat]", (std::array<int, 4>), (std::array<double, 4>))
{
    TestType input = { 1, 2, 3, 4 };
    using OutputType = std::array<typename TestType::value_type, 10>;
    auto n_generator = [](const auto &v) { return v; };
    OutputType expected_values = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
    auto output = onkialgo::repeat_n_times<OutputType>(input, n_generator);
    REQUIRE(std::is_same_v<decltype(output), OutputType>);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
    auto output_with_default_type = onkialgo::repeat_n_times(input, n_generator);
    REQUIRE(std::is_same_v<decltype(output_with_default_type), std::vector<typename TestType::value_type>>);
    REQUIRE(std::equal(std::begin(output_with_default_type), std::end(output_with_default_type), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}

TEMPLATE_TEST_CASE("repeat_n_times using binary n generator with std::array", "[repeat]", (std::array<int, 4>), (std::array<double, 4>))
{
    TestType input1 = { 1, 2, 3, 4 };
    TestType input2 = { 0, 1, 2, 3 };
    using OutputType = std::array<typename TestType::value_type, 16>;
    auto n_generator = [](const auto &first, const auto &second) { return first + second; };
    OutputType expected_values = { 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4 };
    auto output = onkialgo::repeat_n_times<OutputType>(input1, input2, n_generator);
    REQUIRE(std::is_same_v<decltype(output), OutputType>);
    REQUIRE(std::equal(std::begin(output), std::end(output), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));

    auto output_with_default_type = onkialgo::repeat_n_times(input1, input2, n_generator);
    REQUIRE(std::is_same_v<decltype(output_with_default_type), std::vector<typename TestType::value_type>>);
    REQUIRE(std::equal(std::begin(output_with_default_type), std::end(output_with_default_type), std::begin(expected_values), [](const auto &r, const auto &e) { return r == Approx(e); }));
}
