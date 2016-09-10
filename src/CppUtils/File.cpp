#include "CppUtils/File.hpp"

#include <fstream>

#include "CppUtils/Errors.hpp"
#include "CppUtils/Validators.hpp"


using std::string;
using std::ifstream;
using std::istreambuf_iterator;


namespace CppUtils
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

    string content
    {
        istreambuf_iterator<char>(stream),
        istreambuf_iterator<char>(),
    };

    stream.close();
    return content;
}


} // namespace CppUtils
