#include "JCore/Files/JSONFile.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/expectNoThrow.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/invalidResourcePath.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"

using std::move;

namespace JCore {

TEST(JSONFileTest, validCreation) {
    expectNoThrow([]() {
        JSONFile(validResourcePath("json/", "test_config.json"));
    });
}

TEST(JSONFileTest, emptyPath) {
    EXPECT_THROW(JSONFile(""), EmptyStringArg);
}

TEST(JSONFileTest, emptyFile) {
    EXPECT_THROW(JSONFile(invalidResourcePath("json/", "empty.json")), FileError);
}

TEST(JSONFileTest, parseError) {
    EXPECT_THROW(JSONFile(invalidResourcePath("json/", "parse_error.json")), FileError);
}

} // namespace JCore
