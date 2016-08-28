#include "JCore/Errors/MessageBuilders/buildSystemMessage.hpp"


using std::string;


namespace JCore {


string buildSystemMessage(const string & systemName, const string & message) {
    return systemName + " ERROR: " + message;
}


} // namespace JCore
