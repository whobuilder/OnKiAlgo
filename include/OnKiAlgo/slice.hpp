#ifndef ONKIALGO_SLICE_H
#define ONKIALGO_SLICE_H
#include <cstddef>
#include <algorithm>
#include <OnKiGenerics/container_factory.hpp>
#include <OnKiGenerics/remove_cvref.hpp>
namespace onkialgo {
template<typename ResultType, typename Container>
ResultType slice(Container &&c, std::size_t start_index, std ::size_t end_index)
{
    using SourceValueType = typename onkigenerics::ContainerFactory<onkigenerics::remove_cvref_t<Container>>::value_type;
    using SlicedValueType = typename onkigenerics::ContainerFactory<ResultType>::value_type;
    static_assert(std::is_same_v<SourceValueType, SlicedValueType>, "Source and sliced container must have the same value_type!");
    auto size = end_index - start_index;
    auto result = onkigenerics::ContainerFactory<ResultType>::create(size);
    std::copy(
      std::next(std::begin(c), static_cast<ptrdiff_t>(start_index)),
      std::next(std::begin(c), static_cast<ptrdiff_t>(end_index)),
      std::begin(result));
    return result;
}
}// namespace onkialgo

#endif /* ONKIALGO_SLICE_H */
