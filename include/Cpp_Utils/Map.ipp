#include <stdexcept>
#include <iterator>

#include "Cpp_Utils/Fn.hpp"
#include "Cpp_Utils/String.hpp"


namespace Cpp_Utils
{


template<typename Key, typename Value>
using Map_It = typename std::map<Key, Value>::iterator;

template<typename Key, typename Value>
using Map_Const_It = typename std::map<Key, Value>::const_iterator;


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
    Map_Const_It<Key, const Value> it = map.find(key);

    if (it == map.end())
    {
        throw std::runtime_error("ERROR: map doesn't contain that key!");
    }

    return it->second;
}


template<typename Key, typename Value>
const Key & at_value(const std::map<Key, const Value> & map, const Value & value)
{
    Map_Const_It<Key, const Value> it =
        std::find_if(map.begin(), map.end(), [&](const std::pair<Key, const Value> & data) -> bool
        {
            return data.second == value;
        });

    if (it == map.end())
    {
        throw std::runtime_error("ERROR: map doesn't contain that value!");
    }

    return it->first;
}


template<typename Key, typename Value>
std::pair<Key, const Value> at_index(const std::map<Key, const Value> & map, int index)
{
    if (index >= map.size())
    {
        throw std::runtime_error(
            "ERROR: attempting to access map of size " + to_string(map.size()) + " at index " + to_string(index) + "!");
    }

    Map_Const_It<Key, const Value> it = map.begin();
    std::advance(it, index);
    return *it;
}


template<typename Key, typename Value>
std::pair<Key, Value> at_index(const std::map<Key, Value> & map, int index)
{
    if (index >= map.size())
    {
        throw std::runtime_error(
            "ERROR: attempting to access map of size " + to_string(map.size()) + " at index " + to_string(index) + "!");
    }

    Map_Const_It<Key, Value> it = map.begin();
    std::advance(it, index);
    return *it;
}


template<typename Key, typename Value>
void remove(std::map<Key, Value> & map, const Key & key)
{
    if (!contains_key(map, key))
    {
        throw std::runtime_error("ERROR: cannot remove from map as map doesn't contain that key!");
    }

    map.erase(key);
}


} // namespace Cpp_Utils
