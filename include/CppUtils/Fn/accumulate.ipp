#include <algorithm>


namespace CppUtils {


template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initialValue, const Container & container, const Accumulator & accumulator) {
    return std::accumulate(
        container.begin(),
        container.end(),
        initialValue,
        accumulator);
}


} // namespace CppUtils
