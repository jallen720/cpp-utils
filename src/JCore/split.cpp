#include "JCore/split.hpp"

#include <sstream>

using std::vector;
using std::stringstream;
using std::getline;
using String = std::string;

namespace JCore {

vector<String> split(const String& string, const char delimiter) {
    vector<String> elements;
    stringstream stream(string);
    String element;

    while (getline(stream, element, delimiter)) {
        elements.push_back(element);
    }

    return elements;
}

} // namespace JCore
