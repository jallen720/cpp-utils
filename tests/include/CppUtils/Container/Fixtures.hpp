#pragma once


#include <gtest/gtest.h>

#include "CppUtils/JSON.hpp"
#include "CppUtils/Test.hpp"


namespace CppUtils
{


class forEachTest : public testing::Test
{
protected:
    const JSON keyValuePairs = readJSONFile(validResourcePath("json", "key-value-pairs.json"));
};


} // namespace CppUtils
