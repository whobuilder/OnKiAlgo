#ifndef ONKIALGO_SLIDE_H
#define ONKIALGO_SLIDE_H
#include <vector>
#include <OnKiAlgo/container_factory.hpp>
namespace onkialgo {

template<typename ResultType, typename ValuesType>
ResultType slide(ValuesType &&values, std::ptrdiff_t slide_size)
{
    using SourceContainer = std::remove_cv_t<std::remove_reference_t<ValuesType>>;
    using InnerContainer = typename ContainerFactory<ResultType>::value_type;
    using OuterContainer = ResultType;
    auto outer_container_size = static_cast<std::size_t>(static_cast<std::ptrdiff_t>(ContainerFactory<SourceContainer>::size(std::forward<ValuesType>(values))) - (slide_size - 1) ) ;
    auto outer_container = ContainerFactory<OuterContainer>::create(outer_container_size);
    std::transform(std::begin(values), std::prev(std::end(values), (slide_size - 1)), std::begin(outer_container), [&](auto &val) {
        auto inner_container = onkialgo::ContainerFactory<InnerContainer>::create(static_cast<std::size_t>(slide_size));
        std::copy(&val, std::next(&val, slide_size), begin(inner_container));
        return inner_container;
    });
    return outer_container;
}
}// namespace onkialgo

#endif /* ONKIALGO_SLIDE_H */
