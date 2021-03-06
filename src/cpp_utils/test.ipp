#include "cpp_utils/dependencies/catch.hpp"

namespace cpp_utils
{

template<typename T>
void assert_equal_elements(const std::vector<T> & expected_elements, const std::vector<T> & actual_elements)
{
    REQUIRE(expected_elements.size() == actual_elements.size());

    for (auto i = 0u; i < expected_elements.size(); i++)
    {
        REQUIRE(expected_elements[i] == actual_elements[i]);
    }
}

} // namespace cpp_utils
