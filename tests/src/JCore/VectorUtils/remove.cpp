#include "JCore/VectorUtils/remove.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/assertEqualElements.hpp"


using std::vector;


namespace JCore {


TEST(removeTest, validVectorRemoveElement) {
    vector<int> validVector { 1, 2, 1, 3, 4, 3 };

    remove(validVector, 1);
    assertEqualElements({ 2, 1, 3, 4, 3 }, validVector);

    remove(validVector, 3);
    assertEqualElements({ 2, 1, 4, 3 }, validVector);

    remove(validVector, 5);
    assertEqualElements({ 2, 1, 4, 3 }, validVector);
}


TEST(removeTest, emptyVectorRemoveElement) {
    vector<int> emptyVector;

    remove(emptyVector, 1);
    assertEqualElements({}, emptyVector);
}


TEST(removeTest, validVectorRemovePredicate) {
    vector<int> validVector { 1, 2, 3, 4 };

    remove(validVector, [](const int element) -> bool { return element < 3; });
    assertEqualElements({ 2, 3, 4 }, validVector);

    remove(validVector, [](const int element) -> bool { return element > 2; });
    assertEqualElements({ 2, 4 }, validVector);

    remove(validVector, [](const int element) -> bool { return element > 4; });
    assertEqualElements({ 2, 4 }, validVector);
}


TEST(removeTest, emptyVectorRemovePredicate) {
    vector<int> emptyVector;

    remove(emptyVector, [](const int element) -> bool { return element > 0; });
    assertEqualElements({}, emptyVector);
}


} // namespace JCore
