#include "JCore/StringUtils/toString.hpp"

using std::string;

namespace JCore {

template<>
string toString(const bool isTrue) {
    return isTrue ? "true" : "false";
}

} // namespace JCore
