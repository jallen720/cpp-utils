#include <algorithm>
#include <stdexcept>
#include "cpp_utils/string.hpp"

namespace cpp_utils
{

template<typename T>
bool contains(const std::vector<T> & vector, const T & element)
{
    return std::find(vector.begin(), vector.end(), element) != vector.end();
}

template<typename T, typename Predicate>
bool contains(const std::vector<T> & vector, const Predicate & predicate)
{
    return std::find_if(vector.begin(), vector.end(), predicate) != vector.end();
}

template<typename T>
void remove(std::vector<T> & vector, const T & element)
{
    typename std::vector<T>::iterator vector_element = std::find(vector.begin(), vector.end(), element);

    if (vector_element != vector.end())
    {
        vector.erase(vector_element);
    }
}

template<typename T, typename Predicate>
void remove(std::vector<T> & vector, const Predicate & predicate)
{
    typename std::vector<T>::iterator vector_element = std::find_if(vector.begin(), vector.end(), predicate);

    if (vector_element != vector.end())
    {
        vector.erase(vector_element);
    }
}

template<typename T>
void remove_at_index(std::vector<T> & vector, const unsigned int index)
{
    const size_t vector_size = vector.size();

    if (index >= vector_size)
    {
        throw std::runtime_error(
            "ERROR: cannot remove element at index " + cpp_utils::to_string(index) + "; vector only has a size of " +
            cpp_utils::to_string(vector_size));
    }

    vector.erase(vector.begin() + index);
}

template<typename T, typename Comparator>
void sort(std::vector<T> & vector, const Comparator & comparator)
{
    std::sort(vector.begin(), vector.end(), comparator);
}


template<typename T>
void concat(std::vector<T> & to_vector, const std::vector<T> & from_vector)
{
    to_vector.insert(to_vector.end(), from_vector.begin(), from_vector.end());
}

} // namespace cpp_utils
