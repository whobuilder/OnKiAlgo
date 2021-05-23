#ifndef ONKIALGO_CONTAINER_FACTORY_H
#define ONKIALGO_CONTAINER_FACTORY_H
#include <cstddef>
#include <array>
namespace onkialgo {

template<typename Container>
struct ContainerFactory
{
    static Container create(std::size_t size)
    {
        return Container(size);
    }
    template<std::ptrdiff_t N, typename BaseContainer>
    static Container create_with_incremented_size(BaseContainer &&base)
    {
        return Container(base.size() + N);
    }
};
template<typename T, std::size_t N>
struct ContainerFactory<std::array<T, N>>
{
    static std::array<T, N> create(std::size_t)
    {
        return {};
    }
    template<std::ptrdiff_t Difference, typename BaseContainer>
    static std::array<T, N + Difference> create_with_incremented_size(BaseContainer &&)
    {
        return {};
    }
};


}// namespace onkialgo

#endif /* ONKIALGO_CONTAINER_FACTORY_H */
