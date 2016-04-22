#include <algorithm>


namespace JCore {


template<typename T>
void remove(std::vector<T>& vector, const T& element) {
    typename std::vector<T>::iterator vectorElement =
        std::find(
            vector.begin(),
            vector.end(),
            element);

    if (vectorElement != vector.end()) {
        vector.erase(vectorElement);
    }
}


template<typename T, typename Predicate>
void remove(std::vector<T>& vector, const Predicate& predicate) {
    typename std::vector<T>::iterator vectorElement =
        std::find_if(
            vector.begin(),
            vector.end(),
            predicate);

    if (vectorElement != vector.end()) {
        vector.erase(vectorElement);
    }
}


} // namespace JCore
