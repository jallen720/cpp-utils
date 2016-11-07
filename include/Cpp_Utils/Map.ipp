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
    static const auto value_selector = [](const std::pair<Key, Value> & pair) -> Value
    {
        return pair.second;
    };

    return transform<Value>(map, value_selector);
}


template<typename Key, typename Value>
std::vector<Value> get_values(const std::map<Key, const Value> & map)
{
    static const auto value_selector = [](const std::pair<Key, const Value> & pair) -> Value
    {
        return pair.second;
    };

    return transform<Value>(map, value_selector);
}


template<typename Key, typename Value>
const Value & at_key(const std::map<Key, const Value> & map, const Key & key)
{
    const std::map<Key, const Value>::const_iterator it = map.find(key);

    if (it == map.end())
    {
        throw std::runtime_error("ERROR: map does not contain that key!");
    }

    return it->second;
}


} // namespace Cpp_Utils
