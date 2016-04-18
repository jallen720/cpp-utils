#include "JCore/JSON/iterateJSONObject.hpp"


using std::string;


namespace JCore {


void iterateJSONObject(const JSON& jsonObject, const JSONDataCB& jsonDataCB) {
    for (JSON::const_iterator it = jsonObject.begin(); it != jsonObject.end(); it++) {
        jsonDataCB(it.key(), it.value());
    }
}


} // namespace JCore
