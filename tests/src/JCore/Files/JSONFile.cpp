#include "JCore/Files/JSONFile.hpp"

#include <gtest/gtest.h>

#include "JCore/Testing/expectNoThrow.hpp"
#include "JCore/Testing/validResourcePath.hpp"
#include "JCore/Testing/invalidResourcePath.hpp"
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
