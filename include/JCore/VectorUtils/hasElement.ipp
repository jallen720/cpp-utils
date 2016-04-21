#include <algorithm>


namespace JCore {


template<typename T>
bool hasElement(const std::vector<T>& vector, const T& element) {
    return std::find(
        vector.begin(),
        vector.end(),
        element
    ) != vector.end();
}


} // namespace JCore
