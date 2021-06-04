#ifndef ONKIALGO_ARANGE_H
#define ONKIALGO_ARANGE_H
#include <vector>
#include <OnKiGenerics/alternative_type.hpp>
#include <OnKiGenerics/container_factory.hpp>
namespace onkialgo {
template<typename ResultType = void, typename T>
auto arange(T start, T stop, T step)
{
    using OutputType = onkigenerics::AlternativeType<std::vector<T>, ResultType>;
    auto size = static_cast<std::size_t>((stop - start) / step) + 1;
    auto v = onkigenerics::ContainerFactory<OutputType>::create(size);

    T n{ 0 };
    std::generate(begin(v), end(v), [n, start, step]() mutable {
                        auto next= start + n;
                        n+=step;
                        return next; });
    return v;
}
}// namespace onkialgo

#endif /* ONKIALGO_ARANGE_H */
