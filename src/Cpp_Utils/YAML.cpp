#include "Cpp_Utils/YAML.hpp"

#include <vector>
#include <stdexcept>

#include "Cpp_Utils/Validators.hpp"
#include "Cpp_Utils/Errors.hpp"
#include "Cpp_Utils/File.hpp"
#include "Cpp_Utils/Collection.hpp"


using std::string;
using std::vector;
using std::runtime_error;

// yaml-cpp/yaml.h
using YAML::Load;
using YAML::NodeType;


namespace Cpp_Utils
{


YAML_Data read_yaml(const string & yaml_text)
{
    return Load(yaml_text);
}


YAML_Data read_yaml_file(const string & path)
{
    validate_not_empty("path", "read_yaml_file", path);
    YAML_Data yaml;

    try
    {
        yaml = read_yaml(read_file(path));
    }
    catch (const runtime_error & error)
    {
        file_error(path, "read_yaml_file", error.what());
    }

    return yaml;
}


bool contains_key(const YAML_Data & yaml, const string & key)
{
    return yaml[key];
}


string get_type_name(const YAML_Data & yaml)
{
    switch (yaml.Type())
    {
        case NodeType::Null: return "null";
        case NodeType::Scalar: return "scalar";
        case NodeType::Sequence: return "sequence";
        case NodeType::Map: return "map";
        case NodeType::Undefined: return "undefined";
        default: return "undefined";
    };
}


YAML_Data merge(const YAML_Data & a, const YAML_Data & b)
{
    YAML_Data merged = a;

    if ((a.IsMap() || a.IsNull()) && b.IsMap())
    {
        for_each(b, [&](const string & key, const YAML_Data & value) -> void
        {
            if (!contains_key(merged, key))
            {
                merged[key] = value;
            }
            else
            {
                YAML_Data merged_field = merged[key];

                if (merged_field.Type() != value.Type())
                {
                    throw runtime_error("ERROR: mismatched types for key \"" + key + "\" when merging YAML!");
                }
                // Map
                else if (value.IsMap())
                {
                    merged[key] = merge(merged_field, value);
                }
                // Sequence
                else if (value.IsSequence())
                {
                    vector<string> merged_sequence = merged_field.as<vector<string>>();

                    for (const string & element : value.as<vector<string>>())
                    {
                        merged_sequence.push_back(element);
                    }

                    merged[key] = merged_sequence;
                }
                // Scalar
                else
                {
                    merged[key] = value;
                }
            }
        });
    }

    return merged;
}


} // namespace Cpp_Utils
