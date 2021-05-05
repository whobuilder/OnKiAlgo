#ifndef ONKIALGO_ARANGE_H
#define ONKIALGO_ARANGE_H

namespace onkialgo {
template<typename T>
std::vector<T> arange(T start, T stop, T step)
{
    auto size = static_cast<std::size_t>((stop - start) / step) + 1;
    std::vector<T> v(size);
    T n{ 0 };
    std::generate(begin(v), end(v), [n, start, step]() mutable {
                        auto next= start + n;
                        n+=step;
                        return next; });
    return v;
}
}// namespace onkialgo

#endif /* ONKIALGO_ARANGE_H */
