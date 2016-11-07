#include <stdexcept>

#include "Cpp_Utils/Fn.hpp"


namespace Cpp_Utils
{


template<typename Key, typename Value>
using Map_Iterator = typename std::map<Key, Value>::const_iterator;


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
    Map_Iterator<Key, const Value> it = map.find(key);

    if (it == map.end())
    {
        throw std::runtime_error("ERROR: map does not contain that key!");
    }

    return it->second;
}


template<typename Key, typename Value>
const Key & at_value(const std::map<Key, const Value> & map, const Value & value)
{
    Map_Iterator<Key, const Value> it =
        std::find_if(map.begin(), map.end(), [&](const std::pair<Key, const Value> & data) -> bool
        {
            return data.second == value;
        });

    if (it == map.end())
    {
        throw std::runtime_error("ERROR: map does not contain that value!");
    }

    return it->first;
}


} // namespace Cpp_Utils
