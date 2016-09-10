#include <gtest/gtest.h>


namespace Cpp_Utils
{


template<typename T>
void assert_equal_elements(const std::vector<T> & expected_elements, const std::vector<T> & actual_elements)
{
    ASSERT_EQ(expected_elements.size(), actual_elements.size());

    for (auto i = 0u; i < expected_elements.size(); i++)
    {
        ASSERT_EQ(expected_elements[i], actual_elements[i]);
    }
}


} // namespace Cpp_Utils
