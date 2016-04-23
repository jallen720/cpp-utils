namespace JCore {


template<typename T, typename _>
const bool containsKey(const std::map<const T, _>& map, const T& key) {
    return map.find(key) != map.end();
}


template<typename T, typename _>
const bool containsKey(const std::map<T, _>& map, const T& key) {
    return map.find(key) != map.end();
}


} // namespace JCore
