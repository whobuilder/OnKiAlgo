#ifndef ONKIALGO_LINSPACE_H
#define ONKIALGO_LINSPACE_H
#include <vector>
#include <algorithm>
#include <OnKiGenerics/container_factory.hpp>
#include <OnKiGenerics/alternative_type.hpp>

namespace onkialgo {
template<typename ResultType = void, typename T>
auto linspace(T start, T end, std::size_t num, bool end_point = true)
{
    using OutputType = onkigenerics::AlternativeType<std::vector<T>, ResultType>;
    auto div = num;
    if (end_point)
        div -= 1;
    auto step = static_cast<T>((end - start) / static_cast<T>(div));
    if (step == T(0)) {
        return OutputType{ T{ start } };
    }

    auto v = onkigenerics::ContainerFactory<OutputType>::create(num);
    std::generate(std::begin(v), std::end(v), [n = 0, step, start]() mutable { return start + n++ * step; });
    return v;
}
}// namespace onkialgo
#endif /* ONKIALGO_LINSPACE_H */
