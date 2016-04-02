#include "JCore/Exceptions/ArgErrors/NullArg.hpp"

#include "JCore/Exceptions/MessageBuilders/buildArgMessage.hpp"

using std::string;

namespace JCore {

NullArg::NullArg(const string& parameter, const string& function)
    : Error(buildArgMessage(
        parameter,
        function,
        " cannot be null"
    )) {}

} // namespace JCore
