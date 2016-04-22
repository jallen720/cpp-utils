#include "JCore/VectorUtils/removeElement.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/assertEqualElements.hpp"


using std::vector;


namespace JCore {


TEST(removeElementTest, validVector) {
    vector<int> validVector { 1, 2, 3, 4 };

    removeElement(validVector, 1);
    assertEqualElements(validVector, { 2, 3, 4 });

    removeElement(validVector, 3);
    assertEqualElements(validVector, { 2, 4 });
}


TEST(removeElementTest, emptyVector) {
    vector<int> emptyVector;

    removeElement(emptyVector, 1);
    assertEqualElements(emptyVector, {});
}


} // namespace JCore
