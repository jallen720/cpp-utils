#include "CppUtils/FileUtils/File.hpp"

#include <fstream>

#include "CppUtils/StringUtils/split.hpp"
#include "CppUtils/Errors/fileError.hpp"
#include "CppUtils/Errors/Validators/validateNotEmpty.hpp"
#include "CppUtils/Macros/CPPUTILS_MOVABLE_PIMPL_DEFAULT_DEFS.hpp"
#include "CppUtils/Macros/CPPUTILS_COPYABLE_PIMPL_DEFS.hpp"


using std::string;
using std::ifstream;
using std::istreambuf_iterator;


namespace CppUtils {


struct File::Impl {
    const string content;

    explicit Impl(const string & path);
};


static const string & getValidPath(const string & path) {
    validateNotEmpty("path", "File::File", path);
    return path;
}


File::File(const string & path)
    : impl(new Impl(getValidPath(path)))
{}


File::~File() = default;


CPPUTILS_MOVABLE_PIMPL_DEFAULT_DEFS(File)
CPPUTILS_COPYABLE_PIMPL_DEFS(File)


void File::forEachLine(LineCB lineCB) const {
    for (const string & line : split(impl->content, '\n')) {
        lineCB(line);
    }
}


const string & File::getContent() const {
    return impl->content;
}


// Implementation

static void validateStream(const ifstream & stream, const string & path) {
    if (!stream.is_open()) {
        fileError(path, "File::Impl::Impl", "failed to open input stream");
    }
}


static string loadValidContent(const string & path) {
    ifstream stream(path);
    validateStream(stream, path);

    string content {
        istreambuf_iterator<char>(stream),
        istreambuf_iterator<char>()
    };

    stream.close();
    return content;
}


File::Impl::Impl(const string & path)
    : content(loadValidContent(path))
{}


} // namespace CppUtils
