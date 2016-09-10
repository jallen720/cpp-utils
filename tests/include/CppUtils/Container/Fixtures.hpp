#pragma once


#include <gtest/gtest.h>

#include "CppUtils/JSON.hpp"
#include "CppUtils/Test.hpp"


namespace CppUtils
{


class for_each_Test : public testing::Test
{
protected:
    const JSON key_value_pairs = read_json_file(valid_resource_path("json", "key_value_pairs.json"));
};


} // namespace CppUtils
