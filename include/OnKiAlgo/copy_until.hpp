#ifndef ONKIALGO_COPY_UNTIL_H
#define ONKIALGO_COPY_UNTIL_H
#include <OnKiGenerics/alternative_type.hpp>
#include <OnKiGenerics/incremented_type.hpp>
#include <OnKiGenerics/container_factory.hpp>
#include <OnKiGenerics/default_dynamic_container.hpp>
#include <OnKiGenerics/is_std_array.hpp>
#include <OnKiAlgo/find_if.hpp>
#include <vector>
#include <utility>
#include <iterator>
namespace onkialgo {

template<typename ResultType = void, typename Container, typename UnaryFunction>
auto copy_until(Container &&container, UnaryFunction &&pred)
{
    using DefaultType = onkigenerics::DefaultDynamicContainer<Container>;
    using OutputType = onkigenerics::AlternativeType<DefaultType, ResultType>;
    auto it = std::find_if(std::begin(container), std::end(container), pred);
    auto output_size = std::distance(std::begin(container), it);
    OutputType out{};
    if constexpr (!onkigenerics::is_raw_or_std_array_v<OutputType>) {

        out = onkigenerics::ContainerFactory<OutputType>::create(output_size);
    }
    std::copy_n(std::begin(container), output_size, std::begin(out));
    return out;
}

template<typename ResultType = void, class Container1, class Container2, class BinaryFunction>
auto copy_until(Container1 &&c1, Container2 &&c2, BinaryFunction &&pred)
{
    using DefaultType = onkigenerics::DefaultDynamicContainer<Container1>;
    using OutputType = onkigenerics::AlternativeType<DefaultType, ResultType>;
    auto it = onkialgo::implementation::find_if(std::begin(c1), std::end(c1), std::begin(c2), std::forward<BinaryFunction>(pred));
    auto output_size = std::distance(std::begin(c1), it);
    OutputType out{};
    if constexpr (!onkigenerics::is_raw_or_std_array_v<OutputType>) {

        out = onkigenerics::ContainerFactory<OutputType>::create(output_size);
    }
    std::copy_n(std::begin(c1), output_size, std::begin(out));
    return out;
}

}// namespace onkialgo

#endif /* ONKIALGO_COPY_UNTIL_H */
