#include "JCore/Errors/Error.hpp"

#include "JCore/Errors/MessageBuilders/buildSystemMessage.hpp"


using std::runtime_error;
using std::string;


namespace JCore {


Error::Error(const string & message)
    : runtime_error(buildSystemMessage("JCORE", message))
{}


} // namespace JCore
