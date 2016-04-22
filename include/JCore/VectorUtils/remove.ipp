#include <algorithm>


namespace JCore {


template<typename T>
void remove(std::vector<T>& vector, const T& element) {
    vector.erase(
        std::remove(
            vector.begin(),
            vector.end(),
            element),

        vector.end());
}


template<typename T, typename Predicate>
void remove(std::vector<T>& vector, const Predicate& predicate) {
    vector.erase(
        std::remove_if(
            vector.begin(),
            vector.end(),
            predicate),

        vector.end());
}


} // namespace JCore
