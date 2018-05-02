#pragma once

#include <string>
#include <vector>
#include <functional>

namespace cpp_utils
{

template<typename T>
void assert_equal_elements(const std::vector<T> & expected_elements, const std::vector<T> & actual_elements);

void assert_no_throw(const std::function<void()> & block);
std::string invalid_resource_path(const std::string & sub_directory, const std::string & name);
std::string valid_resource_path(const std::string & sub_directory, const std::string & name);

} // namespace cpp_utils

#include "cpp_utils/test.ipp"
