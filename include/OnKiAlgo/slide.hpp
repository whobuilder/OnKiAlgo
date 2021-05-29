#ifndef ONKIALGO_SLIDE_H
#define ONKIALGO_SLIDE_H
#include <vector>
#include <algorithm>
#include <OnKiGenerics/container_factory.hpp>
namespace onkialgo {

template<typename ResultType, typename ValuesType>
ResultType slide(ValuesType &&values, std::ptrdiff_t slide_size)
{
    using InnerContainer = typename onkigenerics::ContainerFactory<ResultType>::value_type;
    using OuterContainer = ResultType;
    auto outer_container = onkigenerics::ContainerFactory<OuterContainer>::create(static_cast<std::size_t>(static_cast<std::ptrdiff_t>(std::size(std::forward<ValuesType>(values))) - (slide_size - 1)));
    std::transform(std::begin(values), std::prev(std::end(values), (slide_size - 1)), std::begin(outer_container), [&](auto &val) {
        auto inner_container = onkigenerics::ContainerFactory<InnerContainer>::create(static_cast<std::size_t>(slide_size));
        std::copy(&val, std::next(&val, slide_size), begin(inner_container));
        return inner_container;
    });
    return outer_container;
}
}// namespace onkialgo

#endif /* ONKIALGO_SLIDE_H */
