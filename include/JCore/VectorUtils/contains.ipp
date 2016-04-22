#include <algorithm>


namespace JCore {


template<typename T>
bool contains(const std::vector<T>& vector, const T& element) {
    return std::find(
        vector.begin(),
        vector.end(),
        element) != vector.end();
}


template<typename T, typename Predicate>
bool contains(const std::vector<T>& vector, const Predicate& predicate) {
    return std::find_if(
        vector.begin(),
        vector.end(),
        predicate) != vector.end();
}


} // namespace JCore
