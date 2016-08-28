#include "CppUtils/JSON/loadJSONFile.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/TestUtils/assertNoThrow.hpp"
#include "CppUtils/TestUtils/validResourcePath.hpp"
#include "CppUtils/TestUtils/invalidResourcePath.hpp"


using std::runtime_error;


namespace CppUtils {


TEST(loadJSONFileTest, loadValidFile) {
    assertNoThrow([]() -> void {
        loadJSONFile(validResourcePath("json", "test-config.json"));
    });
}


TEST(loadJSONFileTest, emptyPath) {
    ASSERT_THROW(loadJSONFile(""), runtime_error);
}


TEST(loadJSONFileTest, emptyFile) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "empty.json")), runtime_error);
}


TEST(loadJSONFileTest, parseError) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "parse-error.json")), runtime_error);
}


} // namespace CppUtils
