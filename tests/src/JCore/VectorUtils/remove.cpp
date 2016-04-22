#include "JCore/VectorUtils/remove.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/assertEqualElements.hpp"


using std::vector;


namespace JCore {


TEST(removeTest, validVectorRemoveElement) {
    vector<int> validVector { 1, 2, 3, 4 };

    remove(validVector, 1);
    assertEqualElements(validVector, { 2, 3, 4 });

    remove(validVector, 3);
    assertEqualElements(validVector, { 2, 4 });
}


TEST(removeTest, emptyVectorRemoveElement) {
    vector<int> emptyVector;

    remove(emptyVector, 1);
    assertEqualElements(emptyVector, {});
}


TEST(removeTest, validVectorRemovePredicate) {
    vector<int> validVector { 1, 2, 3, 4 };

    remove(validVector, [](int element) { return element < 3; });
    assertEqualElements(validVector, { 3, 4 });

    remove(validVector, [](int element) { return element > 3; });
    assertEqualElements(validVector, { 3 });
}


TEST(removeTest, emptyVectorRemovePredicate) {
    vector<int> emptyVector;

    remove(emptyVector, [](int element) { return element > 0; });
    assertEqualElements(emptyVector, {});
}


} // namespace JCore
