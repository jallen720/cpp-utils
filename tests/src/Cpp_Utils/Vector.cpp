#include "Cpp_Utils/Vector.hpp"

#include <gtest/gtest.h>

#include "Cpp_Utils/Test.hpp"


using std::vector;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// contains() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(contains_Test, valid_vector_contains_element)
{
    const vector<int> valid_vector { 1, 2, 3, 4 };

    ASSERT_TRUE(contains(valid_vector, 1));
    ASSERT_FALSE(contains(valid_vector, 5));
}


TEST(contains_Test, empty_vector_contains_element)
{
    const vector<int> empty_vector;

    ASSERT_FALSE(contains(empty_vector, 1));
}


TEST(contains_Test, valid_vector_contains_predicate)
{
    const vector<int> valid_vector { 1, 2, 3, 4 };

    ASSERT_TRUE(contains(valid_vector, [](const int element) -> bool { return element < 3; }));
    ASSERT_TRUE(contains(valid_vector, [](const int element) -> bool { return element == 4; }));
    ASSERT_FALSE(contains(valid_vector, [](const int element) -> bool { return element > 4; }));
    ASSERT_FALSE(contains(valid_vector, [](const int element) -> bool { return element < 1; }));
}


TEST(contains_Test, empty_vector_contains_predicate)
{
    const vector<int> empty_vector;

    ASSERT_FALSE(contains(empty_vector, [](const int element) -> bool { return element >= 1; }));
    ASSERT_FALSE(contains(empty_vector, [](const int element) -> bool { return element == 0; }));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// remove() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(remove_Test, valid_vector_remove_element)
{
    vector<int> valid_vector { 1, 2, 1, 3, 4, 3 };

    remove(valid_vector, 1);
    assert_equal_elements({ 2, 1, 3, 4, 3 }, valid_vector);

    remove(valid_vector, 3);
    assert_equal_elements({ 2, 1, 4, 3 }, valid_vector);

    remove(valid_vector, 5);
    assert_equal_elements({ 2, 1, 4, 3 }, valid_vector);
}


TEST(remove_Test, empty_vector_remove_element)
{
    vector<int> empty_vector;

    remove(empty_vector, 1);
    assert_equal_elements({}, empty_vector);
}


TEST(remove_Test, valid_vector_remove_predicate)
{
    vector<int> valid_vector { 1, 2, 3, 4 };

    remove(valid_vector, [](const int element) -> bool { return element < 3; });
    assert_equal_elements({ 2, 3, 4 }, valid_vector);

    remove(valid_vector, [](const int element) -> bool { return element > 2; });
    assert_equal_elements({ 2, 4 }, valid_vector);

    remove(valid_vector, [](const int element) -> bool { return element > 4; });
    assert_equal_elements({ 2, 4 }, valid_vector);
}


TEST(remove_Test, empty_vector_remove_predicate)
{
    vector<int> empty_vector;

    remove(empty_vector, [](const int element) -> bool { return element > 0; });
    assert_equal_elements({}, empty_vector);
}


} // namespace Cpp_Utils
