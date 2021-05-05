#ifndef ONKIALGO_ROUND_H
#define ONKIALGO_ROUND_H

#include <cmath>

namespace onkialgo {
template<typename T, typename U>
T round(T value, U step)
{
    static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>);//  rounding works for arithmethic values
    return static_cast<T>(std::round(value / static_cast<double>(step)) * step);
}

template<typename T, typename U>
T round_up(T value, U step)
{
    static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>);//  rounding works for arithmethic values
    return static_cast<T>(std::ceil(value / static_cast<double>(step)) * step);
}

template<typename T, typename U>
T round_down(T value, U step)
{
    static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>);//  rounding works for arithmethic values
    return static_cast<T>(std::floor(value / static_cast<double>(step)) * step);
}

}// namespace onkialgo

#endif /* ONKIALGO_ROUND_H */
