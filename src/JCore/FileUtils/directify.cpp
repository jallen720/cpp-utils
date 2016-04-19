#include "JCore/FileUtils/directify.hpp"


using std::string;


namespace JCore {


string directify(const string& directory) {
    return directory.back() == '/'
           ? directory
           : directory + '/';
}


} // namespace JCore
