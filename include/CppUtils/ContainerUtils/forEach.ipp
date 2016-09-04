namespace CppUtils {


template<typename T, typename Callback>
void forEach(const std::vector<T> & vector, const Callback & callback) {
    for (T element : vector) {
        callback(element);
    }
}


template<typename T, typename U, typename Callback>
void forEach(const std::map<const T, U> & map, const Callback & callback) {
    for (const std::pair<const T, U> & element : map) {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void forEach(const std::map<T, U> & map, const Callback & callback) {
    for (const std::pair<T, U> & element : map) {
        callback(element.first, element.second);
    }
}


} // namespace CppUtils
