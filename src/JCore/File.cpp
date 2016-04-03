#include "JCore/File.hpp"

#include <fstream>

#include "JCore/split.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/Errors/Validators/validateNotEmpty.hpp"
#include "JCore/MACROS/JCORE_PIMPL_COPY_DEFS.hpp"

using std::string;
using std::ifstream;
using std::istreambuf_iterator;

namespace JCore {

struct File::Impl {
    const string contents;

    explicit Impl(const string& path);
};

static const string& getValidPath(const string& path) {
    validateNotEmpty("path", "File::File", path);
    return path;
}

File::File(const string& path)
    : impl(new Impl(getValidPath(path))) {}

JCORE_PIMPL_COPY_DEFS(File)

void File::forEachLine(LineCB lineCB) const {
    for (const string& line : split(impl->contents, '\n')) {
        lineCB(line);
    }
}

const string& File::getContents() const {
    return impl->contents;
}

// Implementation

static void validateStream(const ifstream& stream, const string& path) {
    if (!stream.is_open()) {
        throw FileError(path, "File::Impl::Impl", "failed to open input stream");
    }
}

static string getValidContents(const string& path) {
    ifstream stream(path);
    validateStream(stream, path);

    string contents {
        istreambuf_iterator<char>(stream),
        istreambuf_iterator<char>()
    };

    stream.close();
    return contents;
}

File::Impl::Impl(const string& path)
    : contents(getValidContents(path)) {}

} // namespace JCore
