#include <stdexcept>


namespace CppUtils {


template<typename Callback>
void iterateJSON(const JSON & json, const Callback & callback) {
    if (!json.is_object()) {
        throw std::runtime_error("ERROR: Cannot iterate JSON that is not an object!");
    }

    for (JSON::const_iterator it = json.begin(); it != json.end(); it++) {
        callback(it.key(), it.value());
    }
}


} // namespace CppUtils
