#include <vector>
#include <gtest/gtest.h>


namespace CppUtils
{


template<typename T>
void assertEqualElements(
    const std::vector<T> & expectedElements,
    const std::vector<T> & actualElements);


} // namespace CppUtils


#include "CppUtils/TestUtils/assertEqualElements.ipp"
