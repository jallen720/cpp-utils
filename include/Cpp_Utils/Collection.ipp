#include <stdexcept>
#include <algorithm>


namespace Cpp_Utils
{


template<typename T, typename Callback>
void for_each(const std::vector<T> & vector, const Callback & callback)
{
    for (T element : vector)
    {
        callback(element);
    }
}


template<typename T, typename U, typename Callback>
void for_each(const std::map<const T, U> & map, const Callback & callback)
{
    for (const std::pair<const T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void for_each(const std::map<T, U> & map, const Callback & callback)
{
    for (const std::pair<T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void for_each(std::map<const T, U> & map, const Callback & callback)
{
    for (std::pair<const T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void for_each(std::map<T, U> & map, const Callback & callback)
{
    for (std::pair<const T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void for_each(const std::unordered_map<const T, U> & map, const Callback & callback)
{
    for (const std::pair<const T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void for_each(const std::unordered_map<T, U> & map, const Callback & callback)
{
    for (const std::pair<T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void for_each(std::unordered_map<const T, U> & map, const Callback & callback)
{
    for (std::pair<const T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename T, typename U, typename Callback>
void for_each(std::unordered_map<T, U> & map, const Callback & callback)
{
    for (std::pair<const T, U> & element : map)
    {
        callback(element.first, element.second);
    }
}


template<typename Callback>
void for_each(const JSON & json, const Callback & callback)
{
    if (!json.is_object())
    {
        throw std::runtime_error("ERROR: Cannot iterate JSON that is not an object!");
    }

    for (JSON::const_iterator it = json.begin(); it != json.end(); it++)
    {
        callback(it.key(), it.value());
    }
}


template<typename T, typename Predicate>
bool find(T & out, const std::vector<T> & vector, const Predicate & predicate)
{
    auto iterator = std::find_if(vector.begin(), vector.end(), predicate);

    if (iterator != vector.end())
    {
        out = *iterator;
        return true;
    }
    else
    {
        return false;
    }
}


} // namespace Cpp_Utils