#include <vector>
#include <stdexcept>
#include "cpp_utils/yaml.hpp"
#include "cpp_utils/validators.hpp"
#include "cpp_utils/errors.hpp"
#include "cpp_utils/file.hpp"
#include "cpp_utils/collection.hpp"

using std::string;
using std::vector;
using std::runtime_error;
using YAML::Load;
using YAML::Node;
using YAML::NodeType;

namespace Cpp_Utils
{

Node read_yaml(const string & yaml_text)
{
    return Load(yaml_text);
}

Node read_yaml_file(const string & path)
{
    validate_not_empty("path", "read_yaml_file", path);
    Node yaml;

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

bool contains_key(const Node & yaml, const string & key)
{
    return yaml[key];
}

string get_type_name(const Node & yaml)
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

Node merge(const Node & a, const Node & b)
{
    Node merged = a;

    if ((a.IsMap() || a.IsNull()) && b.IsMap())
    {
        for_each(b, [&](const string & key, const Node & value) -> void
        {
            if (!contains_key(merged, key))
            {
                merged[key] = value;
            }
            else
            {
                Node merged_field = merged[key];

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
