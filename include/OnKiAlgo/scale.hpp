#ifndef ONKIALGO_SCALE_H
#define ONKIALGO_SCALE_H

#include <chrono>
#include <type_traits>
namespace onkialgo {

namespace detail {
    template<typename T>
    class DivisionType
    {
    public:
        T val_{};
        auto operator()() { return val_ / val_; }
    };
}// namespace detail
template<typename T>
class LinearScale
{
    using FloatingType = std::conditional_t<std::is_arithmetic_v<T>, double, T>;
    using RatioType = std::conditional_t<std::is_convertible_v<std::invoke_result_t<detail::DivisionType<T>>, double>, double, T>;

    T source_start_;
    T target_start_;
    RatioType ratio_;


public:
    LinearScale(T source_start, T source_end, T target_start, T target_end) : source_start_(source_start), target_start_(target_start)
    {
        ratio_ = static_cast<FloatingType>((target_end - target_start)) / (source_end - source_start);
    }

    T to_target(T source_value)
    {
        if (source_value == source_start_) return source_start_;
        return target_start_ + static_cast<T>(ratio_ * (source_value - source_start_));
    }

    T scale(T source_length)
    {
        return source_length * ratio_;
    }

    T scale_back(T target_length)
    {
        return target_length / ratio_;
    }
};

// std::chrono::duration<double> operator*(std::chrono::duration<double> arg1, std::chrono::duration<double> arg2)
// {
//     auto val = std::chrono::duration<double>{ arg1.count() * arg2.count() };
//     return val;
// }
}// namespace onkialgo

#endif /* ONKIALGO_SCALE_H */
