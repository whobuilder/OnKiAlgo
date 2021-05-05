#include <catch2/catch.hpp>
#include <OnKiAlgo/scale.hpp>
#include <complex>

TEST_CASE("linear interpolate ints", "LinearScale")
{
    auto scaler = onkialgo::LinearScale(1, 5, 10, 60);
    REQUIRE(scaler.to_target(3) == 35);
}

TEST_CASE("linear interpolate double", "[LinearScale]")
{
    auto scaler = onkialgo::LinearScale(1., 5., 10., 60.);
    REQUIRE(scaler.to_target(2) == Approx(22.5));
}

TEST_CASE("linear interpolate chrono", "[LinearScale]")
{
    using Seconds = std::chrono::duration<double>;
    using MilliSeconds = std::chrono::duration<double, std::milli>;
    auto scaler = onkialgo::LinearScale<MilliSeconds>(MilliSeconds{ 1000 }, Seconds{ 5 }, Seconds{ 10 }, Seconds{ 60 });
    REQUIRE(scaler.to_target(Seconds{ 3 }) == Seconds{ 35 });
}

TEST_CASE("interpolate chrono zero division", "[LinearScale]")
{
    using Seconds = std::chrono::duration<double>;
    using MilliSeconds = std::chrono::duration<double, std::milli>;
    auto scaler = onkialgo::LinearScale<MilliSeconds>(MilliSeconds{ 1000 }, Seconds{ 5 }, Seconds{ 10 }, Seconds{ 60 });
    REQUIRE(scaler.to_target(Seconds{ 1 }) == Seconds{ 10 });
}

TEST_CASE("linear scale doubles", "[LinearScale]")
{
    auto scaler = onkialgo::LinearScale(1., 5., 10., 60.);
    REQUIRE(scaler.scale(3) == Approx(37.5));
    REQUIRE(scaler.scale_back(37.5) == Approx(3));
}

TEST_CASE("linear scale chrono", "[LinearScale]")
{
    using Seconds = std::chrono::duration<double>;
    using MilliSeconds = std::chrono::duration<double, std::milli>;
    auto scaler = onkialgo::LinearScale<MilliSeconds>(MilliSeconds{ 1000 }, Seconds{ 5 }, Seconds{ 10 }, Seconds{ 60 });
    REQUIRE(scaler.scale(Seconds{ 3 }) == Seconds{ 37.5 });
    REQUIRE(scaler.scale_back(Seconds{ 37.5 }) == MilliSeconds{ 3000 });
}

TEST_CASE("linear scale complex", "[LinearScale]")
{
    auto scaler = onkialgo::LinearScale(std::complex<double>{ 1, 0 }, std::complex<double>{ 5, 0 }, std::complex<double>{ 10, 0 }, std::complex<double>{ 60, 0 });
    REQUIRE(scaler.scale(std::complex<double>{ 3, 0 }) == std::complex<double>{ 37.5, 0 });
    REQUIRE(scaler.scale_back(std::complex<double>{ 37.5, 0 }) == std::complex<double>{ 3, 0 });
}