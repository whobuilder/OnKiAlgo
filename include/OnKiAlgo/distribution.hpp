#ifndef ONKIALGO_DISTRIBUTION_H
#define ONKIALGO_DISTRIBUTION_H
#include <vector>
#include <random>
#include <type_traits>
#include <algorithm>
#include <OnKiGenerics/container_factory.hpp>
#include <OnKiGenerics/alternative_type.hpp>
namespace onkialgo {
template<typename ResultType = void, typename T>
auto random_uniform_distribution(T start, T stop, std::size_t num)
{
    using OutputType = onkigenerics::AlternativeType<std::vector<T>, ResultType>;
    using uniform_distribution = std::conditional_t<std::is_floating_point_v<T>,
      std::uniform_real_distribution<T>,
      std::conditional_t<std::is_integral_v<T>,
        std::uniform_int_distribution<T>,
        void>>;
    if constexpr (std::is_floating_point_v<T>) {
        stop = std::nextafter(stop, std::numeric_limits<T>::max());
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    uniform_distribution dist(start, stop);
    auto range = onkigenerics::ContainerFactory<OutputType>::create(num);
    std::generate(begin(range), end(range), [&]() { return dist(mt); });
    return range;
}

}// namespace onkialgo
#endif /* ONKIALGO_DISTRIBUTION_H */
