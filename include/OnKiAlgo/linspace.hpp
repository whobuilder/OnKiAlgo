#ifndef ONKIALGO_LINSPACE_H
#define ONKIALGO_LINSPACE_H
#include <vector>
#include <algorithm>
namespace onkialgo {
template<typename T>
std::vector<T> linspace(T start, T end, std::size_t num, bool end_point = true)
{
    auto div = num;
    if (end_point)
        div -= 1;
    auto step = static_cast<T>((end - start) /static_cast<T>( div));
    if (step == T(0))
        return { start };
    std::vector<T> v(num);
    std::generate(std::begin(v), std::end(v), [n = 0, step, start]() mutable { return start + n++ * step; });
    return v;
}
}// namespace onkialgo
#endif /* ONKIALGO_LINSPACE_H */
