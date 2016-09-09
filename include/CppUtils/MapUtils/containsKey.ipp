namespace CppUtils {


template<typename Key, typename Value>
bool containsKey(const std::map<Key, Value> & map, const Key & key) {
    return map.find(key) != map.end();
}


} // namespace CppUtils
