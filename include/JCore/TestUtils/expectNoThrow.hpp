#pragma once

#include <functional>

namespace JCore {

void expectNoThrow(const std::function<void()>& block);

} // namespace JCore
