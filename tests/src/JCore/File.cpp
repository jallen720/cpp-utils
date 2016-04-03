#include "JCore/File.hpp"

#include <gtest/gtest.h>

#include "JCore/Testing/expectNoThrow.hpp"
#include "JCore/Testing/validResourcePath.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"

using std::string;
using std::vector;

namespace JCore {

TEST(FileTest, validCreation) {
    expectNoThrow([] {
        File(validResourcePath("misc/", "test.txt"));
    });
}

TEST(FileTest, invalidFile) {
    EXPECT_THROW(File("does_not_exist"), FileError);
}

TEST(FileTest, emptyPath) {
    EXPECT_THROW(File(""), EmptyStringArg);
}

TEST(FileTest, contentsMatch) {
    static const string expectedResult =
        "line1\n"
        "line2\n"
        "line3\n";

    EXPECT_EQ(expectedResult, File(validResourcePath("misc/", "test.txt")).getContents());
}

TEST(FileTest, linesMatch) {
    static const vector<string> expectedResult {
        "line1",
        "line2",
        "line3",
    };

    vector<string> result;

    File(validResourcePath("misc/", "test.txt")).forEachLine([&](const string& line) {
        result.push_back(line);
    });

    for (auto i = 0u; i < result.size(); i++) {
        EXPECT_EQ(expectedResult[i], result[i]);
    }
}

} // namespace JCore
