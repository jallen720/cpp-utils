#include <algorithm>


namespace Cpp_Utils
{


template<typename T>
bool contains(const std::vector<T> & vector, const T & element)
{
    return std::find(
        vector.begin(),
        vector.end(),
        element) != vector.end();
}


template<typename T, typename Predicate>
bool contains(const std::vector<T> & vector, const Predicate & predicate)
{
    return std::find_if(
        vector.begin(),
        vector.end(),
        predicate) != vector.end();
}


template<typename T>
void remove(std::vector<T> & vector, const T & element)
{
    typename std::vector<T>::iterator vector_element =
        std::find(
            vector.begin(),
            vector.end(),
            element);

    if (vector_element != vector.end())
    {
        vector.erase(vector_element);
    }
}


template<typename T, typename Predicate>
void remove(std::vector<T> & vector, const Predicate & predicate)
{
    typename std::vector<T>::iterator vector_element =
        std::find_if(
            vector.begin(),
            vector.end(),
            predicate);

    if (vector_element != vector.end())
    {
        vector.erase(vector_element);
    }
}


} // namespace Cpp_Utils
