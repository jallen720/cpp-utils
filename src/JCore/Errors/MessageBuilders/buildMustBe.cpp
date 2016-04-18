#include "JCore/Errors/MessageBuilders/buildMustBe.hpp"

#include "JCore/Fn/accumulate.hpp"


using std::string;
using std::vector;


namespace JCore {


static string concatValidArg(const string& mustBe, const string& validArg) {
    return mustBe + "      " + validArg + ",\n";
}


string buildMustBe(const vector<string>& validArgs) {
    return accumulate<string>("\n", validArgs, concatValidArg);
}


} // namespace JCore
