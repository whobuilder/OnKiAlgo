#ifndef ONKIALGO_REPEAT_H
#define ONKIALGO_REPEAT_H
#include <iterator>
#include <algorithm>
#include <numeric>
#include <OnKiGenerics/container_factory.hpp>
#include <OnKiGenerics/alternative_type.hpp>
#include <OnKiGenerics/default_dynamic_container.hpp>
#include <OnKiGenerics/is_std_array.hpp>
namespace onkialgo {
namespace implementation {
template<class InputIt, class OutputIt>
void repeat(InputIt first, InputIt last, OutputIt d_first, typename std::iterator_traits<InputIt>::difference_type n)
{
    while (first != last) {
        d_first = std::fill_n(d_first, n, *first);
        ++first;
    }
}

template<class InputIt, class OutputIt, class UnaryNGenerator>
void repeat_n_times(InputIt first, InputIt last, OutputIt d_first, UnaryNGenerator &&get_n)
{
    using DifferenceType = typename std::iterator_traits<InputIt>::difference_type;
    while (first != last) {
        d_first = std::fill_n(d_first, static_cast<DifferenceType>(get_n(*first)), *first);
        ++first;
    }
}

template<class InputIt1, class InputIt2, class OutputIt, class BinaryNGenerator>
void repeat_n_times(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryNGenerator &&get_n)
{
    using DifferenceType = typename std::iterator_traits<InputIt1>::difference_type;
    while (first1 != last1) {
        d_first = std::fill_n(d_first, static_cast<DifferenceType>(get_n(*first1, *first2)), *first1);
        ++first1;
        ++first2;
    }
}

}// namespace implementation

template<class ResultType = void, class Container>
auto repeat(Container &&c, typename std::iterator_traits<decltype(std::begin(std::declval<Container>()))>::difference_type n)
{
    using DefaultType = onkigenerics::DefaultDynamicContainer<Container>;
    using OutputType = onkigenerics::AlternativeType<DefaultType, ResultType>;
    OutputType out{};
    if constexpr (!onkigenerics::is_raw_or_std_array_v<OutputType>) {
        std::size_t output_size = std::size(c) * static_cast<std::size_t>(n);
        out = onkigenerics::ContainerFactory<OutputType>::create(output_size);
    }
    implementation::repeat(std::begin(c), std::end(c), std::begin(out), n);
    return out;
}

template<class ResultType = void, class Container, class UnaryNGenerator>
auto repeat_n_times(Container &&c, UnaryNGenerator &&get_n)
{
    using DefaultType = onkigenerics::DefaultDynamicContainer<Container>;
    using OutputType = onkigenerics::AlternativeType<DefaultType, ResultType>;
    OutputType out{};
    if constexpr (!onkigenerics::is_raw_or_std_array_v<OutputType>) {
        std::size_t output_size = std::transform_reduce(std::begin(c), std::end(c), std::size_t{ 0 }, std::plus<>{}, [&get_n](auto &&v) { return static_cast<std::size_t>(get_n(v)); });
        out = onkigenerics::ContainerFactory<OutputType>::create(output_size);
    }
    implementation::repeat_n_times(std::begin(c), std::end(c), std::begin(out), std::forward<UnaryNGenerator>(get_n));
    return out;
}

template<class ResultType = void, class Container1, class Container2, class BinaryNGenerator>
auto repeat_n_times(Container1 &&c1, Container2 &&c2, BinaryNGenerator &&get_n)
{
    using DefaultType = onkigenerics::DefaultDynamicContainer<Container1>;
    using OutputType = onkigenerics::AlternativeType<DefaultType, ResultType>;
    OutputType out{};
    if constexpr (!onkigenerics::is_raw_or_std_array_v<OutputType>) {
        std::size_t output_size = std::transform_reduce(
          std::begin(c1), std::end(c1), std::begin(c2), std::size_t{ 0 }, std::plus<>{}, [&get_n](auto &&v1, auto &&v2) { return static_cast<std::size_t>(get_n(v1, v2)); });
        out = onkigenerics::ContainerFactory<OutputType>::create(output_size);
    }
    implementation::repeat_n_times(std::begin(c1), std::end(c1), std::begin(c2), std::begin(out), std::forward<BinaryNGenerator>(get_n));
    return out;
}
}// namespace onkialgo

#endif /* ONKIALGO_REPEAT_H */
