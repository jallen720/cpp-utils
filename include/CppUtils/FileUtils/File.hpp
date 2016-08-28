#pragma once


#include <memory>
#include <string>
#include <functional>

#include "CppUtils/Macros/CPPUTILS_MOVABLE_DECLS.hpp"
#include "CppUtils/Macros/CPPUTILS_COPYABLE_DECLS.hpp"


namespace CppUtils {


class File final {
private:
    using LineCB = const std::function<void(const std::string &)> &;

public:
    explicit File(const std::string & path);
    ~File();
    CPPUTILS_MOVABLE_DECLS(File)
    CPPUTILS_COPYABLE_DECLS(File)
    void forEachLine(LineCB lineCB) const;
    const std::string & getContent() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};


} // namespace CppUtils
