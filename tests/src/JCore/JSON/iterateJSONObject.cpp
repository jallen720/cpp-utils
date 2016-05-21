#include "JCore/JSON/iterateJSONObject.hpp"

#include <string>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

#include "JCore/JSON/loadJSONFile.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/assertEqualElements.hpp"
#include "JCore/TestUtils/assertNoThrow.hpp"


using std::string;
using std::vector;
using std::domain_error;


namespace JCore {


TEST(iterateJSONObjectTest, validIteratedData) {
    const vector<string> expectedKeys {
        "key0",
        "key1",
        "key2"
    };

    const vector<int> expectedValues { 0, 1, 2 };
    vector<string> actualKeys;
    vector<int> actualValues;
    JSON jsonObject = loadJSONFile(validResourcePath("json", "key-value-pairs.json"));

    iterateJSONObject(jsonObject, [&](const string & key, const JSON & value) -> void {
        actualKeys.push_back(key);
        actualValues.push_back(value.get<int>());
    });

    assertEqualElements(expectedKeys, actualKeys);
    assertEqualElements(expectedValues, actualValues);
}


TEST(iterateJSONObjectTest, unalphabeticalKeysIteratedAlphabetically) {
    const vector<string> expectedKeys { "a", "b", "c", "d", "e", "f" };
    vector<string> actualKeys;
    JSON jsonObject = loadJSONFile(validResourcePath("json", "unalphabetical-keys.json"));

    iterateJSONObject(jsonObject, [&](const string & key, const JSON &) -> void {
        actualKeys.push_back(key);
    });

    assertEqualElements(expectedKeys, actualKeys);
}


TEST(iterateJSONObjectTest, iterateDifferentTypes) {
    JSON jsonObject = loadJSONFile(validResourcePath("json", "types.json"));
    const auto blank = [&](const string &, const JSON &) -> void {};

    assertNoThrow([&]() -> void {
        iterateJSONObject(jsonObject["object"], blank);
    });

    ASSERT_THROW(iterateJSONObject(jsonObject["list"], blank), domain_error);
    ASSERT_THROW(iterateJSONObject(jsonObject["key"], blank), domain_error);
}


} // namespace JCore
