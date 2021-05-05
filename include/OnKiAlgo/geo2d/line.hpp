#ifndef ONKIALGO_GEO2D_LINE_H
#define ONKIALGO_GEO2D_LINE_H
#define POINT2D_CONCEPT(point)                                     \
    static_assert(std::is_same_v<decltype(p1.x), decltype(p1.y)>); \
    static_assert(std::is_arithmetic_v<decltype(p1.x)>)

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

}// namespace geo2d
}// namespace onkialgo

#endif /* ONKIALGO_GEO2D_LINE_H */
