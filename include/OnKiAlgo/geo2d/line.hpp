#ifndef ONKIALGO_GEO2D_LINE_H
#define ONKIALGO_GEO2D_LINE_H
#define POINT2D_CONCEPT(point)                                           \
    static_assert(std::is_same_v<decltype(point.x), decltype(point.y)>); \
    static_assert(std::is_arithmetic_v<decltype(point.x)>)

#include <type_traits>


namespace onkialgo {
namespace geo2d {

template<typename PointType>
auto length(PointType p1, PointType p2)
{
    POINT2D_CONCEPT(p1);
    return std::sqrt(std::pow(p2.x - p1.x, decltype(p1.x){ 2 }) + std::pow(p2.y - p1.y, decltype(p1.y){ 2 }));
}

template<typename PointType>
auto dot_product(PointType p1, PointType p2)
{
    POINT2D_CONCEPT(p1);
    return p1.x * p2.x + p1.y * p2.y;
}

template<typename PointType>
auto unit_vector(PointType p1, PointType p2)
{
    POINT2D_CONCEPT(p1);
    using UnderlyingType = decltype(p1.x);
    auto l = length(p1, p2);
    return PointType{ static_cast<UnderlyingType>((p2.x - p1.x) / l), static_cast<UnderlyingType>((p2.y - p1.y) / l) };
}

template<typename PointType>
PointType normal_unit_vector(PointType p1, PointType p2)
{
    POINT2D_CONCEPT(p1);
    auto unit = unit_vector(p1, p2);
    return PointType{ -unit.y, unit.x };
}

template<typename PointType>
PointType point_on_line(PointType p1, PointType p2, decltype(p1.x) portion)
{
    POINT2D_CONCEPT(p1);
    return { p1.x + (p2.x - p1.x) * portion,
        p1.y + (p2.y - p1.y) * portion };
}

template<typename PointType>
auto slope(PointType p1, PointType p2)
{
    POINT2D_CONCEPT(p1);
    using FloatingType = std::conditional_t<std::is_floating_point_v<decltype(p1.x)>, decltype(p1.x), double>;
    return static_cast<FloatingType>(p2.y - p1.y) / (p2.x - p1.x);
}

template<typename PointType>
bool is_on_line(PointType start, PointType end, PointType to_check)
{
    POINT2D_CONCEPT(start);
    return slope(start, end) == slope(to_check, end)
           && to_check.x >= start.x && to_check.x <= end.x;
}

}// namespace geo2d
}// namespace onkialgo

#endif /* ONKIALGO_GEO2D_LINE_H */
