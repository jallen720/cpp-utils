#include "CppUtils/Errors/MessageBuilders/buildSystemMessage.hpp"


using std::string;


namespace CppUtils
{


string buildSystemMessage(const string & systemName, const string & message)
{
    return systemName + " ERROR: " + message;
}


} // namespace CppUtils
