#include "JCore/Exceptions/MessageBuilders/buildSystemMessage.hpp"

using std::string;

namespace JCore {

string buildSystemMessage(const string& system, const string& message) {
    return system + " ERROR: " + message;
}

} // namespace JCore
