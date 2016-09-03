namespace CppUtils {


template<typename T, typename Callback>
void forEach(const std::vector<T> & vector, const Callback & callback) {
    for (T element : vector) {
        callback(element);
    }
}


} // namespace CppUtils
