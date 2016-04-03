#pragma once

#include <memory>
#include <string>
#include <functional>

#include "JCore/MACROS/JCORE_PIMPL_COPY_DECLS.hpp"

namespace JCore {

class File {
private:
    using LineCB = const std::function<void(const std::string&)>&;

public:
    explicit File(const std::string& path);
    JCORE_PIMPL_COPY_DECLS(File)
    void forEachLine(LineCB lineCB) const;
    const std::string& getContent() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace JCore
