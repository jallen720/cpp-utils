#include <vector>
#include <gtest/gtest.h>


namespace JCore {


template<typename T>
void assertEqualElements(
    const std::vector<T> & expectedElements,
    const std::vector<T> & actualElements);


} // namespace JCore


#include "JCore/TestUtils/assertEqualElements.ipp"
