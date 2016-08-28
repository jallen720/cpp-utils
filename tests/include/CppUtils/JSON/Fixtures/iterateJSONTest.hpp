#pragma once


#include <gtest/gtest.h>

#include "CppUtils/JSON/JSON.hpp"
#include "CppUtils/JSON/loadJSONFile.hpp"
#include "CppUtils/TestUtils/validResourcePath.hpp"


namespace CppUtils {


class iterateJSONTest : public testing::Test {
protected:
    JSON keyValuePairs = loadJSONFile(validResourcePath("json", "key-value-pairs.json"));
};


} // namespace CppUtils
