#include "CppUtils/JSON/iterateJSON.hpp"

#include <string>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/JSON/Fixtures/iterateJSONTest.hpp"
#include "CppUtils/JSON/loadJSONFile.hpp"
#include "CppUtils/TestUtils/validResourcePath.hpp"
#include "CppUtils/TestUtils/assertEqualElements.hpp"
#include "CppUtils/TestUtils/assertNoThrow.hpp"


using std::string;
using std::vector;
using std::runtime_error;
using std::domain_error;


namespace CppUtils {


TEST_F(iterateJSONTest, validIteratedData) {
    const vector<string> expectedKeys {
        "key0",
        "key1",
        "key2"
    };

    const vector<int> expectedValues { 0, 1, 2 };
    vector<string> actualKeys;
    vector<int> actualValues;

    iterateJSON(keyValuePairs, [&](const string & key, const int value) -> void {
        actualKeys.push_back(key);
        actualValues.push_back(value);
    });

    assertEqualElements(expectedKeys, actualKeys);
    assertEqualElements(expectedValues, actualValues);
}


TEST_F(iterateJSONTest, unalphabeticalKeysIteratedAlphabetically) {
    const vector<string> expectedKeys { "a", "b", "c", "d", "e", "f" };
    vector<string> actualKeys;
    JSON json = loadJSONFile(validResourcePath("json", "unalphabetical-keys.json"));

    iterateJSON(json, [&](const string & key, const JSON &) -> void {
        actualKeys.push_back(key);
    });

    assertEqualElements(expectedKeys, actualKeys);
}


TEST_F(iterateJSONTest, iterateDifferentTypes) {
    JSON json = loadJSONFile(validResourcePath("json", "types.json"));
    const auto blank = [](const string &, const JSON &) -> void {};

    assertNoThrow([&]() -> void {
        iterateJSON(json["object"], blank);
    });

    ASSERT_THROW(iterateJSON(json["list"], blank), runtime_error);
    ASSERT_THROW(iterateJSON(json["key"], blank), runtime_error);
}


TEST_F(iterateJSONTest, incorrectValueType) {
    const auto callback = [](const string &, const string &) -> void {};

    // keyValuePairs has values of type int, so passing a callback that takes a string as the value
    // type will fail.
    ASSERT_THROW(iterateJSON(keyValuePairs, callback), domain_error);
}


} // namespace CppUtils
