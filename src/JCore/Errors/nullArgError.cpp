#include "JCore/Errors/nullArgError.hpp"

#include <stdexcept>

#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"


using std::string;
using std::runtime_error;


namespace JCore {


void nullArgError(const string & parameter, const string & function) {
    throw runtime_error(buildArgMessage(
        parameter,
        function,
        " cannot be null"));
}


} // namespace JCore
