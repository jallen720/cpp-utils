#pragma once


#include <memory>
#include <string>
#include <functional>

#include "JCore/Macros/JCORE_MOVABLE_DECLS.hpp"
#include "JCore/Macros/JCORE_COPYABLE_DECLS.hpp"


namespace JCore {


class File final {
private:
    using LineCB = const std::function<void(const std::string &)> &;

public:
    explicit File(const std::string & path);
    ~File();
    JCORE_MOVABLE_DECLS(File)
    JCORE_COPYABLE_DECLS(File)
    void forEachLine(LineCB lineCB) const;
    const std::string & getContent() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};


} // namespace JCore
