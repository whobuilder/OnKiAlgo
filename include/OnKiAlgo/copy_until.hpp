#ifndef ONKIALGO_COPY_UNTIL_H
#define ONKIALGO_COPY_UNTIL_H

namespace onkialgo {

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt copy_until(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred)
{
    while (first != last) {
        if (pred(*first)) {
            break;
        }
        *d_first++ = *first;
        first++;
    }
    return d_first;
}

template<class InputIt1, class InputIt2, class OutputIt, class BinaryPredicate>
OutputIt copy_until(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryPredicate pred)
{
    while (first1 != last1) {
        if (pred(*first1, *first2)) {
            break;
        }
        *d_first++ = *first1;
        first1++;
        first2++;
    }
    return d_first;
}

}// namespace onkialgo

#endif /* ONKIALGO_COPY_UNTIL_H */
