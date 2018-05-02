#include <stdexcept>
#include "cpp_utils/vector.hpp"
#include "cpp_utils/test.hpp"

using std::vector;
using std::runtime_error;

namespace cpp_utils
{

TEST_CASE("vector::contains() - valid vector contains element", "[vector][contains]")
{
    const vector<int> valid_vector { 1, 2, 3, 4 };
    REQUIRE(contains(valid_vector, 1));
    REQUIRE_FALSE(contains(valid_vector, 5));
}

TEST_CASE("vector::contains() - empty vector contains element", "[vector][contains]")
{
    const vector<int> empty_vector;
    REQUIRE_FALSE(contains(empty_vector, 1));
}

TEST_CASE("vector::contains() - valid vector contains predicate", "[vector][contains]")
{
    const vector<int> valid_vector { 1, 2, 3, 4 };
    REQUIRE(contains(valid_vector, [](const int element) -> bool { return element < 3; }));
    REQUIRE(contains(valid_vector, [](const int element) -> bool { return element == 4; }));
    REQUIRE_FALSE(contains(valid_vector, [](const int element) -> bool { return element > 4; }));
    REQUIRE_FALSE(contains(valid_vector, [](const int element) -> bool { return element < 1; }));
}

TEST_CASE("vector::contains() - empty vector contains predicate", "[vector][contains]")
{
    const vector<int> empty_vector;
    REQUIRE_FALSE(contains(empty_vector, [](const int element) -> bool { return element >= 1; }));
    REQUIRE_FALSE(contains(empty_vector, [](const int element) -> bool { return element == 0; }));
}

TEST_CASE("vector::remove() - valid vector remove element", "[vector][remove]")
{
    vector<int> valid_vector { 1, 2, 1, 3, 4, 3 };
    remove(valid_vector, 1);
    assert_equal_elements({ 2, 1, 3, 4, 3 }, valid_vector);
    remove(valid_vector, 3);
    assert_equal_elements({ 2, 1, 4, 3 }, valid_vector);
    remove(valid_vector, 5);
    assert_equal_elements({ 2, 1, 4, 3 }, valid_vector);
}

TEST_CASE("vector::remove() - empty vector remove element", "[vector][remove]")
{
    vector<int> empty_vector;
    remove(empty_vector, 1);
    assert_equal_elements({}, empty_vector);
}

TEST_CASE("vector::remove() - valid vector remove predicate", "[vector][remove]")
{
    vector<int> valid_vector { 1, 2, 3, 4 };
    remove(valid_vector, [](const int element) -> bool { return element < 3; });
    assert_equal_elements({ 2, 3, 4 }, valid_vector);
    remove(valid_vector, [](const int element) -> bool { return element > 2; });
    assert_equal_elements({ 2, 4 }, valid_vector);
    remove(valid_vector, [](const int element) -> bool { return element > 4; });
    assert_equal_elements({ 2, 4 }, valid_vector);
}

TEST_CASE("vector::remove() - empty vector remove predicate", "[vector][remove]")
{
    vector<int> empty_vector;
    remove(empty_vector, [](const int element) -> bool { return element > 0; });
    assert_equal_elements({}, empty_vector);
}

TEST_CASE("vector::remove_at_index() - valid vector", "[vector][remove_at_index]")
{
    vector<int> valid_vector { 1, 2, 1, 3, 4, 3 };
    remove_at_index(valid_vector, 2);
    assert_equal_elements({ 1, 2, 3, 4, 3 }, valid_vector);
    remove_at_index(valid_vector, 4);
    assert_equal_elements({ 1, 2, 3, 4 }, valid_vector);
    remove_at_index(valid_vector, 0);
    assert_equal_elements({ 2, 3, 4 }, valid_vector);
    REQUIRE_THROWS_AS(remove_at_index(valid_vector, 3), runtime_error);
}

TEST_CASE("vector::remove_at_index() - empty vector", "[vector][remove_at_index]")
{
    vector<int> empty_vector;
    REQUIRE_THROWS_AS(remove_at_index(empty_vector, 0), runtime_error);
}

TEST_CASE("vector::sort() - valid vector", "[vector][sort]")
{
    vector<int> values { 2, 4, 3, 1 };

    sort(values, [](const int value_a, const int value_b) -> bool
    {
        return value_a > value_b;
    });

    assert_equal_elements({ 4, 3, 2, 1 }, values);

    sort(values, [](const int value_a, const int value_b) -> bool
    {
        return value_a < value_b;
    });

    assert_equal_elements({ 1, 2, 3, 4 }, values);
}

TEST_CASE("vector::concat() - valid vectors", "[vector][concat]")
{
    vector<int> to_vector { 1, 2, 3 };
    vector<int> from_vector { 4, 5, 6 };
    concat(to_vector, from_vector);
    assert_equal_elements({ 1, 2, 3, 4, 5, 6 }, to_vector);
}

TEST_CASE("vector::concat() - empty to vector", "[vector][concat]")
{
    vector<int> to_vector;
    vector<int> from_vector { 4, 5, 6 };
    concat(to_vector, from_vector);
    assert_equal_elements({ 4, 5, 6 }, to_vector);
}

TEST_CASE("vector::concat() - empty from vector", "[vector][concat]")
{
    vector<int> to_vector { 1, 2, 3 };
    vector<int> from_vector;
    concat(to_vector, from_vector);
    assert_equal_elements({ 1, 2, 3 }, to_vector);
}

} // namespace cpp_utils
