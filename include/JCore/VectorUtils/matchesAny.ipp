#include <algorithm>


namespace JCore {


template<typename T, typename Predicate>
bool matchesAny(const std::vector<T>& vector, const Predicate& predicate) {
    return std::find_if(
        vector.begin(),
        vector.end(),
        predicate
    ) != vector.end();
}


} // namespace JCore
