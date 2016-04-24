#include "JCore/FileUtils/File.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/assertNoThrow.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/assertEqualElements.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"


using std::string;
using std::vector;


namespace JCore {


TEST(FileTest, validCreation) {
    assertNoThrow([]() {
        File(validResourcePath("misc", "test.txt"));
    });
}


TEST(FileTest, invalidFile) {
    ASSERT_THROW(File("does_not_exist"), FileError);
}


TEST(FileTest, emptyPath) {
    ASSERT_THROW(File(""), EmptyStringArg);
}


TEST(FileTest, contentMatch) {
    const string expectedContent =
        "line1\n"
        "line2\n"
        "line3\n";

    ASSERT_EQ(expectedContent, File(validResourcePath("misc", "test.txt")).getContent());
}


TEST(FileTest, linesMatch) {
    const vector<string> expectedLines {
        "line1",
        "line2",
        "line3",
    };

    vector<string> actualLines;

    File(validResourcePath("misc", "test.txt")).forEachLine([&](const string& line) {
        actualLines.push_back(line);
    });

    assertEqualElements(expectedLines, actualLines);
}


} // namespace JCore
