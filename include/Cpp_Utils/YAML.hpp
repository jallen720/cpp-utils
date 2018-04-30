#pragma once

#include <string>
#include <yaml-cpp/yaml.h>

namespace Cpp_Utils
{

YAML::Node read_yaml(const std::string & yaml_text);
YAML::Node read_yaml_file(const std::string & path);
bool contains_key(const YAML::Node & yaml, const std::string & key);
std::string get_type_name(const YAML::Node & yaml);
YAML::Node merge(const YAML::Node & a, const YAML::Node & b);

} // namespace Cpp_Utils
