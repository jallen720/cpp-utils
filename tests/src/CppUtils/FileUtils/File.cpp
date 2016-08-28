#include "CppUtils/FileUtils/File.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/TestUtils/assertNoThrow.hpp"
#include "CppUtils/TestUtils/validResourcePath.hpp"
#include "CppUtils/TestUtils/assertEqualElements.hpp"


using std::string;
using std::vector;
using std::runtime_error;


namespace CppUtils {


TEST(FileTest, validCreation) {
    assertNoThrow([]() -> void {
        File(validResourcePath("misc", "test.txt"));
    });
}


TEST(FileTest, invalidFile) {
    ASSERT_THROW(File("does_not_exist"), runtime_error);
}


TEST(FileTest, emptyPath) {
    ASSERT_THROW(File(""), runtime_error);
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

    File(validResourcePath("misc", "test.txt")).forEachLine([&](const string & line) -> void {
        actualLines.push_back(line);
    });

    assertEqualElements(expectedLines, actualLines);
}


} // namespace CppUtils
