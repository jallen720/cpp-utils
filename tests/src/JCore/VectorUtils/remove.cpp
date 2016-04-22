#include "JCore/VectorUtils/remove.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/assertEqualElements.hpp"


using std::vector;


namespace JCore {


TEST(removeTest, validVector) {
    vector<int> validVector { 1, 2, 3, 4 };

    remove(validVector, 1);
    assertEqualElements(validVector, { 2, 3, 4 });

    remove(validVector, 3);
    assertEqualElements(validVector, { 2, 4 });
}


TEST(removeTest, emptyVector) {
    vector<int> emptyVector;

    remove(emptyVector, 1);
    assertEqualElements(emptyVector, {});
}


} // namespace JCore
