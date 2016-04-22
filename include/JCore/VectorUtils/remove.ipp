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


} // namespace JCore
