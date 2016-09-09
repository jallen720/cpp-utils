#include "CppUtils/Fn/transform.hpp"

#include <map>
#include <string>

#include "CppUtils/TestUtils/assertEqualElements.hpp"


using std::vector;
using std::map;
using std::pair;
using std::string;


namespace CppUtils
{


TEST(transformTest, transformVector)
{
    const vector<string> strings
    {
        "string0",
        "string1",
        "string2",
    };

    assertEqualElements(
        {
            "0string0!",
            "1string1!",
            "2string2!",
        },
        transform<string>(strings, [](const string & element) -> string
        {
            return element.back() + element + "!";
        }));
}


TEST(transformTest, transformMap)
{
    const map<int, int> mappedNumbers
    {
        { 1 , 0 },
        { 2 , 3 },
        { 6 , 5 },
    };

    assertEqualElements(
        { 1, 5, 11 },
        transform<int>(mappedNumbers, [](const pair<int, int> & numbers) -> int
        {
            return numbers.first + numbers.second;
        }));
}


} // namespace CppUtils
