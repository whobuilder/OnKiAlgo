#include <catch2/catch.hpp>
#include <OnKiAlgo/round.hpp>

TEST_CASE("round ints", "[round<int, int>]")
{
    REQUIRE(onkialgo::round(4, 10) == 0);
    REQUIRE(onkialgo::round(5, 10) == 10);
    REQUIRE(onkialgo::round(6, 100) == 0);
    REQUIRE(onkialgo::round(60, 100) == 100);
}


TEST_CASE("round doubles", "[round<double, int>]")
{
    REQUIRE(onkialgo::round(4.5, 10) == Approx(0));
    REQUIRE(onkialgo::round(5.5, 10) == Approx(10));
    REQUIRE(onkialgo::round(6.1, 100) == Approx(0));
    REQUIRE(onkialgo::round(60.3, 100) == Approx(100));
    REQUIRE(onkialgo::round(60.3, 70) == Approx(70));
}

TEST_CASE("round doubles with double accuracy", "[round<double, double>]")
{
    REQUIRE(onkialgo::round(4.52, 0.1) == Approx(4.5));
    REQUIRE(onkialgo::round(5.565, 0.01) == Approx(5.57));
    REQUIRE(onkialgo::round(5.566, 0.6) == Approx(5.4));
}

TEST_CASE("round_down ints", "[round_down<int, int>]")
{
    REQUIRE(onkialgo::round_down(4, 10) == 0);
    REQUIRE(onkialgo::round_down(5, 10) == 0);
    REQUIRE(onkialgo::round_down(60, 100) == 0);
    REQUIRE(onkialgo::round_down(160, 100) == 100);
}


TEST_CASE("round_down doubles", "[round_down<double, int>]")
{
    REQUIRE(onkialgo::round_down(4.5, 10) == Approx(0));
    REQUIRE(onkialgo::round_down(5.5, 10) == Approx(0));
    REQUIRE(onkialgo::round_down(6.1, 100) == Approx(0));
    REQUIRE(onkialgo::round_down(60.3, 100) == Approx(0));
    REQUIRE(onkialgo::round_down(76.3, 70) == Approx(70));
}

TEST_CASE("round_down doubles with double accuracy", "[round_down<double, double>]")
{
    REQUIRE(onkialgo::round_down(4.52, 0.1) == Approx(4.5));
    REQUIRE(onkialgo::round_down(5.565, 0.01) == Approx(5.56));
    REQUIRE(onkialgo::round_down(5.566, 0.5) == Approx(5.5));
}

TEST_CASE("round_up ints", "[round_up<int, int>]")
{
    REQUIRE(onkialgo::round_up(4, 10) == 10);
    REQUIRE(onkialgo::round_up(5, 10) == 10);
    REQUIRE(onkialgo::round_up(6, 100) == 100);
    REQUIRE(onkialgo::round_up(60, 100) == 100);
}


TEST_CASE("round_up doubles", "[round_up<double, int>]")
{
    REQUIRE(onkialgo::round_up(4.5, 10) == Approx(10));
    REQUIRE(onkialgo::round_up(5.5, 10) == Approx(10));
    REQUIRE(onkialgo::round_up(6.1, 100) == Approx(100));
    REQUIRE(onkialgo::round_up(60.3, 100) == Approx(100));
    REQUIRE(onkialgo::round_up(60.3, 70) == Approx(70));
}

TEST_CASE("round_up doubles with double accuracy", "[round_up<double, double>]")
{
    REQUIRE(onkialgo::round_up(4.52, 0.1) == Approx(4.6));
    REQUIRE(onkialgo::round_up(5.565, 0.01) == Approx(5.57));
    REQUIRE(onkialgo::round_up(5.566, 0.6) == Approx(6.0));
}