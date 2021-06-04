#ifndef ONKIALGO_BRING_TO_FRONT_H
#define ONKIALGO_BRING_TO_FRONT_H

#include <algorithm>

namespace onkialgo {
namespace implementation {

template<typename ForwardIt, typename T>
ForwardIt bring_to_front(ForwardIt first, ForwardIt last, const T &value)
{
    std::ptrdiff_t i = 0;
    while (true) {
        auto it = std::find(std::next(first, i), last, value);
        if (it == last) break;

        std::rotate(std::next(first, i), it, last);
        ++i;
    }
    return std::next(first, i);
}

template<typename ForwardIt, typename UnaryFunction>
ForwardIt bring_to_front_if(ForwardIt first, ForwardIt last, UnaryFunction &&pred)
{
    std::ptrdiff_t i = 0;
    while (true) {
        auto it = std::find_if(std::next(first, i), last, std::forward<UnaryFunction>(pred));
        if (it == last) break;
        std::rotate(std::next(first, i), it, last);
        ++i;
    }
    return std::next(first, i);
}
}// namespace implementation

template<typename Container, typename T>
auto bring_to_front(Container &container, const T &value) -> decltype(std::begin(container))
{
    return implementation::bring_to_front(std::begin(container), std::end(container), value);
}

template<typename Container, typename UnaryFunction>
auto bring_to_front_if(Container &container, UnaryFunction &&pred) -> decltype(std::begin(container))
{
    return implementation::bring_to_front_if(std::begin(container), std::end(container), std::forward<UnaryFunction>(pred));
}
}// namespace onkialgo
#endif /* ONKIALGO_BRING_TO_FRONT_H */
