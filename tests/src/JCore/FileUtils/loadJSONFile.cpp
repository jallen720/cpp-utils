#include "JCore/FileUtils/loadJSONFile.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/assertNoThrow.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/invalidResourcePath.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"


namespace JCore {


TEST(loadJSONFileTest, loadValidFile) {
    assertNoThrow([]() {
        loadJSONFile(validResourcePath("json", "test_config.json"));
    });
}


TEST(loadJSONFileTest, emptyPath) {
    ASSERT_THROW(loadJSONFile(""), EmptyStringArg);
}


TEST(loadJSONFileTest, emptyFile) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "empty.json")), FileError);
}


TEST(loadJSONFileTest, parseError) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "parse_error.json")), FileError);
}


} // namespace JCore
