#include "CppUtils/Fn/transform.hpp"


namespace CppUtils
{


template<typename Key, typename Value>
std::vector<Value> getValues(const std::map<Key, Value> & map)
{
    return transform<Value>(map, [](const std::pair<Key, Value> & pair) -> Value
    {
        return pair.second;
    });
}


template<typename Key, typename Value>
std::vector<Value> getValues(const std::map<Key, const Value> & map)
{
    return transform<Value>(map, [](const std::pair<Key, const Value> & pair) -> Value
    {
        return pair.second;
    });
}


} // namespace CppUtils
