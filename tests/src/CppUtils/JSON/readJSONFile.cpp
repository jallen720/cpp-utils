#include "CppUtils/JSON/readJSONFile.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/TestUtils/assertNoThrow.hpp"
#include "CppUtils/TestUtils/validResourcePath.hpp"
#include "CppUtils/TestUtils/invalidResourcePath.hpp"


using std::runtime_error;


namespace CppUtils {


TEST(readJSONFileTest, loadValidFile) {
    assertNoThrow([]() -> void {
        readJSONFile(validResourcePath("json", "test-config.json"));
    });
}


TEST(readJSONFileTest, emptyPath) {
    ASSERT_THROW(readJSONFile(""), runtime_error);
}


TEST(readJSONFileTest, emptyFile) {
    ASSERT_THROW(readJSONFile(invalidResourcePath("json", "empty.json")), runtime_error);
}


TEST(readJSONFileTest, parseError) {
    ASSERT_THROW(readJSONFile(invalidResourcePath("json", "parse-error.json")), runtime_error);
}


} // namespace CppUtils
