#ifndef ONKIALGO_SLIDE_H
#define ONKIALGO_SLIDE_H
#include <vector>
#include <OnKiAlgo/generic_helpers.hpp>
namespace onkialgo {

template<typename ResultType, typename ValuesType>
ResultType slide(ValuesType &&values, std::size_t slide_size)
{
    using InnerContainer = typename ResultType::value_type;
    using OuterContainer = ResultType;
    auto outer_container = onkialgo::initialize_with_size(OuterContainer{}, values.size() - (slide_size - 1));
    std::transform(begin(values), std::prev(end(values), (slide_size - 1)), begin(outer_container), [&](auto &val) {
        auto inner_container = onkialgo::initialize_with_size(InnerContainer{}, slide_size);
        std::copy(&val, std::next(&val, slide_size), begin(inner_container));
        return inner_container;
    });
    return outer_container;
}
}// namespace onkialgo

#endif /* ONKIALGO_SLIDE_H */
