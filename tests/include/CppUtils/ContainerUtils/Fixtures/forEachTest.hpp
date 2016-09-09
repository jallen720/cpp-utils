#pragma once


#include <gtest/gtest.h>

#include "CppUtils/JSON/JSON.hpp"
#include "CppUtils/JSON/readJSONFile.hpp"
#include "CppUtils/TestUtils/validResourcePath.hpp"


namespace CppUtils
{


class forEachTest : public testing::Test
{
protected:
    const JSON keyValuePairs = readJSONFile(validResourcePath("json", "key-value-pairs.json"));
};


} // namespace CppUtils
