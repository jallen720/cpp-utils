#include "JCore/toString.hpp"

using std::string;

namespace JCore {

template<>
const string toString(bool val) {
    return val == true ? "true" : "false";
}

} // namespace JCore
