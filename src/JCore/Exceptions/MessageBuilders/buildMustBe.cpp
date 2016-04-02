#include "JCore/Exceptions/MessageBuilders/buildMustBe.hpp"

#include "JCore/accumulate.hpp"

using std::string;
using std::vector;

namespace JCore {

string concatValidArg(const string& mustBe, const string& validArg) {
    return mustBe + "      " + validArg + ",\n";
}

string buildMustBe(const vector<string>& validArgs) {
    return accumulate<string>("\n", validArgs, concatValidArg);
}

} // namespace JCore
