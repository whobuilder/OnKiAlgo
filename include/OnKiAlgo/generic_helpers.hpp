#ifndef ONKIALGO_GENERIC_HELPERS_H
#define ONKIALGO_GENERIC_HELPERS_H
#include <cstddef>
#include <array>
namespace onkialgo {

template<typename Container>
Container container_with_size(const Container &&, std::size_t size) { return Container(size); }

template<typename T, std::size_t N>
std::array<T, N> container_with_size(const std::array<T, N> &&, std::size_t) { return {}; }
}// namespace onkialgo

#endif /* ONKIALGO_GENERIC_HELPERS_H */
