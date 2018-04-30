const COMPILER_OPTIONS = [ "std=c++14", "ggdb", "Wall", "Wextra", "pedantic-errors", "c" ];

// cpp_utils
const CPP_UTILS_SRC_DIR = "src";
const CPP_UTILS_TESTS_SRC_DIR = "tests/src";

// yaml-cpp
const YAML_CPP_DIR = "<PACKAGES>/yaml-cpp";
const YAML_CPP_LIB_DIR = "<PACKAGES>/yaml-cpp/build";

module.exports =
{
    "source_extension": "cpp",
    "header_extension": "hpp",
    "targets":
    {
        "cpp_utils":
        {
            "type": "shared_library",
            "source_dirs": [ `src/cpp_utils` ],
            "include_dirs":
            [
                CPP_UTILS_SRC_DIR,
                `${ YAML_CPP_DIR }/include`,
            ],
            "library_dirs":
            [
                `${ YAML_CPP_DIR }/build`,
            ],
            "libraries": [ "yaml-cpp" ],
            "library_import_paths": [],
            "pkg_config": [],
            "compiler_options": COMPILER_OPTIONS,
            "linker_options": [],
        },
        "test":
        {
            "type": "application",
            "main": `${ CPP_UTILS_TESTS_SRC_DIR }/main`,
            "source_dirs": [ `${ CPP_UTILS_TESTS_SRC_DIR }/cpp_utils` ],
            "include_dirs":
            [
                CPP_UTILS_SRC_DIR,
                `${ YAML_CPP_DIR }/include`,
            ],
            "library_dirs": [],
            "libraries": [ "yaml-cpp", "cpp_utils" ],
            "library_import_paths":
            [
                "lib/libcpp_utils.so",
                `${ YAML_CPP_LIB_DIR }/libyaml-cpp.so.0.6`,
            ],
            "pkg_config": [],
            "compiler_options": COMPILER_OPTIONS,
            "linker_options": [ `Wl,-rpath,'$$ORIGIN/lib'` ],
        },
    }
};
