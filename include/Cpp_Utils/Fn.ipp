#include <algorithm>


namespace Cpp_Utils
{


template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initial_value, const Container & container, const Accumulator & accumulator)
{
    return std::accumulate(container.begin(), container.end(), initial_value, accumulator);
}


template<typename T, typename Container, typename Transformer>
std::vector<T> transform(const Container & container, const Transformer & transformer)
{
    std::vector<T> result(container.size());
    std::transform(container.begin(), container.end(), result.begin(), transformer);
    return result;
}


template<typename T, typename Predicate>
std::vector<T> filter(const std::vector<T> & vector, const Predicate & predicate)
{
    std::vector<T> result;

    for (const T & element : vector)
    {
        if (predicate(element))
        {
            result.push_back(element);
        }
    }

    return result;
}


} // namespace Cpp_Utils
