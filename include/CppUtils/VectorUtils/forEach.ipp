namespace CppUtils {


template<typename T, typename Function>
void forEach(const std::vector<T> & vector, const Function & function) {
    for (T element : vector) {
        function(element);
    }
}


} // namespace CppUtils
