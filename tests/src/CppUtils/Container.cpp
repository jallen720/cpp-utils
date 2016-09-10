#include "CppUtils/Container.hpp"

#include <stdexcept>

#include "CppUtils/Container/Fixtures.hpp"
#include "CppUtils/Test.hpp"
#include "CppUtils/String.hpp"


using std::vector;
using std::map;
using std::string;
using std::runtime_error;
using std::domain_error;


namespace CppUtils
{


TEST_F(forEachTest, forEachVector)
{
    int result = 0;
    const vector<int> values { 1, 2, 3, 4 };
    const auto valueHandler = [&](const int value) -> void { result += value; };

    forEach(values, valueHandler);
    ASSERT_EQ(result, 10);
    forEach(values, valueHandler);
    ASSERT_EQ(result, 20);
}


TEST_F(forEachTest, forEachEmptyVector)
{
    // Function passed to forEach() should never be called if vector is empty.
    forEach(vector<int> {}, [](const int /*value*/) -> void { FAIL(); });
}


TEST_F(forEachTest, forEachMap)
{
    vector<string> result;

    const map<string, const int> values
    {
        { "first"  , 3 },
        { "second" , 1 },
        { "third"  , 2 },
    };

    forEach(values, [&](const string & key, const int value) -> void
    {
        result.push_back(key + toString(value));
    });

    assertEqualElements(
        {
            "first3",
            "second1",
            "third2",
        },
        result);
}


TEST_F(forEachTest, forEachEmptyMap)
{
    // Function passed to forEach() should never be called if map is empty.
    forEach(map<string, int> {}, [](const string & /*key*/, const int /*value*/) -> void { FAIL(); });
}


TEST_F(forEachTest, forEachJSON)
{
    const vector<string> expectedKeys
    {
        "key0",
        "key1",
        "key2",
    };

    const vector<int> expectedValues { 0, 1, 2 };
    vector<string> actualKeys;
    vector<int> actualValues;

    forEach(keyValuePairs, [&](const string & key, const int value) -> void
    {
        actualKeys.push_back(key);
        actualValues.push_back(value);
    });

    assertEqualElements(expectedKeys, actualKeys);
    assertEqualElements(expectedValues, actualValues);
}


TEST_F(forEachTest, unalphabeticalKeysIteratedAlphabetically)
{
    const vector<string> expectedKeys { "a", "b", "c", "d", "e", "f" };
    vector<string> actualKeys;
    const JSON json = readJSONFile(validResourcePath("json", "unalphabetical-keys.json"));

    forEach(json, [&](const string & key, const JSON &) -> void
    {
        actualKeys.push_back(key);
    });

    assertEqualElements(expectedKeys, actualKeys);
}


TEST_F(forEachTest, differentJSONTypes)
{
    const JSON json = readJSONFile(validResourcePath("json", "types.json"));
    const auto callback = [](const string &, const JSON &) -> void {};

    assertNoThrow([&]() -> void { forEach(json["object"], callback); });
    ASSERT_THROW(forEach(json["list"], callback), runtime_error);
    ASSERT_THROW(forEach(json["key"], callback), runtime_error);
}


TEST_F(forEachTest, incorrectValueType)
{
    const auto callback = [](const string &, const string &) -> void {};

    // keyValuePairs has values of type int, so passing a callback that takes a string as the value
    // type will fail.
    ASSERT_THROW(forEach(keyValuePairs, callback), domain_error);
}


} // namespace CppUtils
