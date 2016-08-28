namespace CppUtils {


template<typename JSONDataCB>
void iterateJSON(const JSON & json, const JSONDataCB & jsonDataCB) {
    for (JSON::const_iterator it = json.begin(); it != json.end(); it++) {
        jsonDataCB(it.key(), it.value());
    }
}


} // namespace CppUtils
