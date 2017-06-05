#pragma once


#include <string>
#include <yaml-cpp/yaml.h>


namespace Cpp_Utils
{


using YAML_Data = YAML::Node;

YAML_Data read_yaml(const std::string & yaml_text);
YAML_Data read_yaml_file(const std::string & path);
bool contains_key(const YAML_Data & yaml, const std::string & key);
std::string get_type_name(const YAML_Data & yaml);
YAML_Data merge(const YAML_Data & a, const YAML_Data & b);


} // namespace Cpp_Utils
