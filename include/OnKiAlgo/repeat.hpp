#ifndef ONKIALGO_REPEAT_H
#define ONKIALGO_REPEAT_H
#include <iterator>
#include <algorithm>
namespace onkialgo {
template<class InputIt, class OutputIt>
void repeat(InputIt first, InputIt last, OutputIt d_first, typename std::iterator_traits<InputIt>::difference_type n)
{
    while (first != last) {
        d_first = std::fill_n(d_first, n, *first);
        ++first;
    }
}

template<class InputIt, class OutputIt, class UnaryNGenerator>
void repeat_n_times(InputIt first, InputIt last, OutputIt d_first, UnaryNGenerator get_n)
{
    using DifferenceType = typename std::iterator_traits<InputIt>::difference_type;
    while (first != last) {
        d_first = std::fill_n(d_first, static_cast<DifferenceType>(get_n(*first)), *first);
        ++first;
    }
}

template<class InputIt1, class InputIt2, class OutputIt, class BinaryNGenerator>
void repeat_n_times(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryNGenerator get_n)
{
    using DifferenceType = typename std::iterator_traits<InputIt1>::difference_type;
    while (first1 != last1) {
        d_first = std::fill_n(d_first, static_cast<DifferenceType>(get_n(*first1, *first2)), *first1);
        ++first1;
        ++first2;
    }
}

}// namespace onkialgo

#endif /* ONKIALGO_REPEAT_H */
