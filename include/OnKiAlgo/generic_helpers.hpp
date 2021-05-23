#ifndef ONKIALGO_GENERIC_HELPERS_H
#define ONKIALGO_GENERIC_HELPERS_H
#include <cstddef>
#include <array>
namespace onkialgo {

template<typename Container>
Container initialize_with_size(const Container &&, std::size_t size) { return Container(size); }

template<typename T, std::size_t N>
std::array<T, N> initialize_with_size(const std::array<T, N> &&, std::size_t) { return {}; }

template<std::ptrdiff_t i, typename Container>
auto container_with_size_increased_by(Container &&c)
{
    using ContainerType = std::remove_cv_t<std::remove_reference_t<Container>>;
    return ContainerType(c.size() + i);
}

template<std::ptrdiff_t i, typename T, std::size_t N>
std::array<T, N + i> container_with_size_increased_by(std::array<T, N> &&)
{
    return {};
}

template<std::ptrdiff_t i, typename T, std::size_t N>
std::array<T, N + i> container_with_size_increased_by(std::array<T, N> &)
{
    return {};
}

}// namespace onkialgo

#endif /* ONKIALGO_GENERIC_HELPERS_H */
