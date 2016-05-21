#include "JCore/JSON/iterateJSON.hpp"

#include <string>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

#include "JCore/JSON/Fixtures/iterateJSONTest.hpp"
#include "JCore/JSON/loadJSONFile.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/assertEqualElements.hpp"
#include "JCore/TestUtils/assertNoThrow.hpp"


using std::string;
using std::vector;
using std::domain_error;


namespace JCore {


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

    ASSERT_THROW(iterateJSON(json["list"], blank), domain_error);
    ASSERT_THROW(iterateJSON(json["key"], blank), domain_error);
}


TEST_F(iterateJSONTest, incorrectValueType) {
    const auto incorrectValueTypeCB = [](const string &, const string &) -> void {};

    // keyValuePairs has values of type int, so passing a callback that takes a string as the value
    // type will fail.
    ASSERT_THROW(iterateJSON(keyValuePairs, incorrectValueTypeCB), domain_error);
}


} // namespace JCore
