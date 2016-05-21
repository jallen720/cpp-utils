#pragma once


#include <gtest/gtest.h>

#include "JCore/JSON/JSON.hpp"
#include "JCore/JSON/loadJSONFile.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"


namespace JCore {


class iterateJSONTest : public testing::Test {
protected:
    JSON keyValuePairs = loadJSONFile(validResourcePath("json", "key-value-pairs.json"));
};


} // namespace JCore
