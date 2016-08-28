#include "CppUtils/FileUtils/directify.hpp"


using std::string;


namespace CppUtils {


string directify(const string & directory) {
    return directory.back() == '/'
           ? directory
           : directory + '/';
}


} // namespace CppUtils
