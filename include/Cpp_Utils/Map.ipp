#include <stdexcept>

#include "Cpp_Utils/Fn.hpp"


namespace Cpp_Utils
{


template<typename Key, typename Value>
bool contains_key(const std::map<Key, Value> & map, const Key & key)
{
    return map.find(key) != map.end();
}


template<typename Key, typename Value>
std::vector<Value> get_values(const std::map<Key, Value> & map)
{
    return transform<Value>(map, [](const std::pair<Key, Value> & pair) -> Value
    {
        return pair.second;
    });
}


template<typename Key, typename Value>
std::vector<Value> get_values(const std::map<Key, const Value> & map)
{
    return transform<Value>(map, [](const std::pair<Key, const Value> & pair) -> Value
    {
        return pair.second;
    });
}


template<typename Key, typename Value>
const Value & at_key(const std::map<Key, const Value> & map, const Key & key)
{
    if (!contains_key(map, key))
    {
        throw std::runtime_error("ERROR: map does not contain key \"" + key + "\"!");
    }

    return map.at(key);
}


} // namespace Cpp_Utils
