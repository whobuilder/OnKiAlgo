#ifndef ONKIALGO_BRING_TO_FRONT_H
#define ONKIALGO_BRING_TO_FRONT_H

#include <algorithm>

namespace onkialgo {
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
}// namespace onkialgo
#endif /* ONKIALGO_BRING_TO_FRONT_H */
