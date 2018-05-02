#include <fstream>
#include "cpp_utils/file.hpp"
#include "cpp_utils/errors.hpp"
#include "cpp_utils/validators.hpp"

using std::string;
using std::ifstream;
using std::istreambuf_iterator;

namespace cpp_utils
{

string platform_path(string path)
{
#ifdef _WIN32
    // Convert to Windows directory format.
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == '/')
        {
            path[i] = '\\';
        }
    }
#endif

    return path;
}

string directify(const string & directory)
{
#ifdef _WIN32
    static const char DIRECTORY_DELIMITER = '\\';
#elif __gnu_linux__
    static const char DIRECTORY_DELIMITER = '/';
#endif

    return directory.back() == DIRECTORY_DELIMITER
           ? directory
           : directory + DIRECTORY_DELIMITER;
}

string read_file(string path)
{
    path = platform_path(path);
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

} // namespace cpp_utils
