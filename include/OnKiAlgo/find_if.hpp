#ifndef ONKIALGO_FIND_IF_H
#define ONKIALGO_FIND_IF_H
#include <iterator>
#include <utility>
namespace onkialgo {
namespace implementation {

template<typename InputIt1, typename InputIt2, typename BinaryFunction>
InputIt1 find_if(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryFunction &&pred)
{
    for (; first1 != last1; ++first1) {
        if (pred(*first1, *(first2++))) {
            return first1;
        }
    }
    return last1;
}

}// namespace implementation

template<typename Container1, typename Container2, typename BinaryFunction>
auto find_if(const Container1 &c1, Container2 &&c2, BinaryFunction &&pred) -> decltype(std::begin(c1))
{
    return implementation::find_if(std::begin(c1), std::end(c1), std::begin(c2), std::forward<BinaryFunction>(pred));
}
}// namespace onkialgo

#endif /* ONKIALGO_FIND_IF_H */
