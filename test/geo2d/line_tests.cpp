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

TEST_CASE("Dot product ints", "[line]")
{
    Point2D<int> p1{ 3, 0 };
    Point2D<int> p2{ 0, 5 };
    REQUIRE(onkialgo::geo2d::dot_product(p1, p2) == 0);
}

TEST_CASE("Unit vector ints", "[line]")
{
    Point2D<int> p1{ 3, 0 };
    Point2D<int> p2{ 0, 4 };
    REQUIRE(onkialgo::geo2d::unit_vector(p1, p2) == Point2D<int>{ 0, 0 });
}

TEST_CASE("Unit vector floats", "[line]")
{
    Point2D<float> p1{ 3, 0 };
    Point2D<float> p2{ 0, 4 };
    REQUIRE(onkialgo::geo2d::unit_vector(p1, p2) == Point2D<float>{ -0.6f, 0.8f });
}

TEST_CASE("Normal unit vector", "[line]")
{
    Point2D<float> p1{ 3, 0 };
    Point2D<float> p2{ 0, 4 };
    REQUIRE(onkialgo::geo2d::normal_unit_vector(p1, p2) == Point2D<float>{ -0.8f, -0.6f });
    p1 = { 0, 1 };
    p2 = { 0, 0 };
    REQUIRE(onkialgo::geo2d::normal_unit_vector(p1, p2) == Point2D<float>{ 1.f, 0.f });
}

TEST_CASE("Point on the line", "[line]")
{
    Point2D<float> p1{ 1, 2 };
    Point2D<float> p2{ 4, 6 };
    REQUIRE(onkialgo::geo2d::point_on_line(p1, p2, 0.5) == Point2D<float>{ 2.5f, 4.f });
}