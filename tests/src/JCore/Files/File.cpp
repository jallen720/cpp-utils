#include "JCore/Files/File.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/expectNoThrow.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/assertEqualElements.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"

using std::string;
using std::vector;

namespace JCore {

TEST(FileTest, validCreation) {
    expectNoThrow([]() {
        File(validResourcePath("misc/", "test.txt"));
    });
}

TEST(FileTest, invalidFile) {
    EXPECT_THROW(File("does_not_exist"), FileError);
}

TEST(FileTest, emptyPath) {
    EXPECT_THROW(File(""), EmptyStringArg);
}

TEST(FileTest, contentMatch) {
    static const string expectedContent =
        "line1\n"
        "line2\n"
        "line3\n";

    EXPECT_EQ(expectedContent, File(validResourcePath("misc/", "test.txt")).getContent());
}

TEST(FileTest, linesMatch) {
    static const vector<string> expectedLines {
        "line1",
        "line2",
        "line3",
    };

    vector<string> actualLines;

    File(validResourcePath("misc/", "test.txt")).forEachLine([&](const string& line) {
        actualLines.push_back(line);
    });

    assertEqualElements(expectedLines, actualLines);
}

} // namespace JCore
