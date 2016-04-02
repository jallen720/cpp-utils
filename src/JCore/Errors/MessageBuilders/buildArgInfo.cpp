#include "JCore/Errors/MessageBuilders/buildArgInfo.hpp"

using std::string;

namespace JCore {

string buildArgInfo(const string& mustBe) {
    return ":\n"
           "    must be: " + mustBe;
}

} // namespace JCore
