#include "JCore/JSON/loadJSONFile.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "JCore/TestUtils/assertNoThrow.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/invalidResourcePath.hpp"


using std::runtime_error;


namespace JCore {


TEST(loadJSONFileTest, loadValidFile) {
    assertNoThrow([]() -> void {
        loadJSONFile(validResourcePath("json", "testConfig.json"));
    });
}


TEST(loadJSONFileTest, emptyPath) {
    ASSERT_THROW(loadJSONFile(""), runtime_error);
}


TEST(loadJSONFileTest, emptyFile) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "empty.json")), runtime_error);
}


TEST(loadJSONFileTest, parseError) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "parseError.json")), runtime_error);
}


} // namespace JCore
