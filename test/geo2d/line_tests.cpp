#include <catch2/catch.hpp>
#include <OnKiAlgo/geo2d/line.hpp>

template<typename T>
struct Point2D
{
    T x;
    T y;
    friend bool operator==(Point2D p1, Point2D p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
};

TEST_CASE("length defined by two double points", "[line]")
{
    Point2D<double> p1{ 3, 0 };
    Point2D<double> p2{ 0, 4 };
    REQUIRE(onkialgo::geo2d::length(p1, p2) == Approx(5));
}

TEST_CASE("length defined by two int points", "[line]")
{
    Point2D<int> p1{ 3, 0 };
    Point2D<int> p2{ 0, 5 };
    REQUIRE(onkialgo::geo2d::length(p1, p2) == Approx(5.8309518948));
}