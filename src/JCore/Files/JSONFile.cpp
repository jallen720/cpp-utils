#include "JCore/Files/JSONFile.hpp"

#include <stdexcept>

#include "JCore/Files/File.hpp"
#include "JCore/Errors/Validators/validateNotEmpty.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/StringUtils/areEqual.hpp"
#include "JCore/MACROS/JCORE_PIMPL_COPY_DEFS.hpp"

using std::string;
using std::invalid_argument;

namespace JCore {

struct JSONFile::Impl {
    const Content content;

    explicit Impl(const string& path);
};

const string& getValidPath(const string& path) {
    validateNotEmpty("path", "JSONFile::JSONFile", path);
    return path;
}

JSONFile::JSONFile(const string& path)
    : impl(new Impl(getValidPath(path))) {}

JCORE_PIMPL_COPY_DEFS(JSONFile)

auto JSONFile::getContent() const -> const Content& {
    return impl->content;
}

// Implementation

static string getErrorMessage(const invalid_argument& error) {
    return areEqual(error.what(), "parse error - unexpected end of input")
           ? "file is empty"
           : error.what();
}

static JSONFile::Content loadContent(const string& path) {
    try {
        return JSONFile::Content::parse(File(path).getContent());
    }
    catch (const std::invalid_argument& error) {
        throw FileError(
            "JSON",
            path,
            "JSONFile::Impl::Impl",
            getErrorMessage(error)
        );
    }
}

JSONFile::Impl::Impl(const string& path)
    : content(loadContent(path)) {}

} // namespace JCore
