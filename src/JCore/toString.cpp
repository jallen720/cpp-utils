#include "JCore/toString.hpp"

using std::string;

namespace JCore {

template<>
const string toString(bool isTrue) {
    return isTrue ? "true" : "false";
}

} // namespace JCore
