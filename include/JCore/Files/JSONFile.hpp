#pragma once

#include <memory>
#include <string>

#include "JCore/Files/JSON/json.hpp"
#include "JCore/MACROS/JCORE_PIMPL_COPY_DECLS.hpp"

namespace JCore {

class JSONFile {
public:
    using Content = nlohmann::json;

public:
    explicit JSONFile(const std::string& path);
    JCORE_PIMPL_COPY_DECLS(JSONFile)
    const Content& getContent() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace JCore
