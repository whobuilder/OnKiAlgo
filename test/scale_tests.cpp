#include <catch2/catch.hpp>
#include <OnKiAlgo/scale.hpp>
#include <complex>
#include <chrono>

TEMPLATE_TEST_CASE("linear interpolate", "[LinearScale]", int, double, std::chrono::duration<double>)
{
    auto scaler = onkialgo::LinearScale(TestType{ 1 }, TestType{ 5 }, TestType{ 10 }, TestType{ 60 });
    REQUIRE(scaler.to_target(TestType{ 3 }) == TestType{ 35 });
}

TEST_CASE("interpolate chrono zero division", "[LinearScale]")
{
    using Seconds = std::chrono::duration<double>;
    using MilliSeconds = std::chrono::duration<double, std::milli>;
    auto scaler = onkialgo::LinearScale<MilliSeconds>(MilliSeconds{ 1000 }, Seconds{ 5 }, Seconds{ 10 }, Seconds{ 60 });
    REQUIRE(scaler.to_target(Seconds{ 1 }) == Seconds{ 10 });
}

TEMPLATE_TEST_CASE("linear scale", "[LinearScale]", double, std::chrono::duration<double>)
{
    auto scaler = onkialgo::LinearScale(TestType{ 1. }, TestType{ 5. }, TestType{ 10. }, TestType{ 60. });
    REQUIRE(scaler.scale(TestType{ 3 }) == TestType{ 37.5 });
    REQUIRE(scaler.scale_back(TestType{ 37.5 }) == TestType{ 3 });
}

TEST_CASE("linear scale complex", "[LinearScale]")
{
    auto scaler = onkialgo::LinearScale(std::complex<double>{ 1, 0 }, std::complex<double>{ 5, 0 }, std::complex<double>{ 10, 0 }, std::complex<double>{ 60, 0 });
    REQUIRE(scaler.scale(std::complex<double>{ 3, 0 }) == std::complex<double>{ 37.5, 0 });
    REQUIRE(scaler.scale_back(std::complex<double>{ 37.5, 0 }) == std::complex<double>{ 3, 0 });
}