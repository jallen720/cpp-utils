#pragma once


#include <gtest/gtest.h>

#include "Cpp_Utils/JSON.hpp"
#include "Cpp_Utils/Test.hpp"


namespace Cpp_Utils
{


class for_each_Test : public testing::Test
{
protected:
    const JSON key_value_pairs = read_json_file(valid_resource_path("json", "key_value_pairs.json"));
};


} // namespace Cpp_Utils
