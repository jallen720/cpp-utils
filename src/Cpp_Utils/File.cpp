#include "Cpp_Utils/File.hpp"

#include <fstream>

#include "Cpp_Utils/Errors.hpp"
#include "Cpp_Utils/Validators.hpp"


using std::string;
using std::ifstream;
using std::istreambuf_iterator;


namespace Cpp_Utils
{


string directify(const string & directory)
{
    return directory.back() == '/'
           ? directory
           : directory + '/';
}


string read_file(const string & path)
{
    validate_not_empty("path", "read_file", path);
    ifstream stream(path);

    if (!stream.is_open())
    {
        file_error(path, "read_file", "failed to open input stream");
    }

    string content { istreambuf_iterator<char>(stream), istreambuf_iterator<char>() };
    stream.close();
    return content;
}


bool file_exists(const string & path)
{
    return ifstream(path).good();
}


} // namespace Cpp_Utils
