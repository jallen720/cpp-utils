#!/usr/bin/python3.4

import sys
import shutil
import os
import fileinput


__ROOT_DIR_EXTENSIONS = {
    "include/"  : [".hpp", ".ipp"],
    "src/"      : [".cpp"],
    "tests/src/": [".cpp"],
}


def check_make_destination_dirs(filename, origin_subdir, destination_subdir):
    def check_make_destination_dir(destination_dir):
        if not os.path.isdir(destination_dir):
            os.makedirs(destination_dir)

    for root_dir, extensions in __ROOT_DIR_EXTENSIONS.items():
        for extension in extensions:
            if os.path.isfile(root_dir + origin_subdir + filename + extension):
                check_make_destination_dir(root_dir + destination_subdir)


def get_header_paths(filename, origin_subdir, destination_subdir):
    header_paths = {
        "origin": [],
        "destination": []
    }

    for header_extension in __ROOT_DIR_EXTENSIONS["include/"]:
        full_filename           = filename + header_extension
        origin_header_path      = origin_subdir + full_filename
        destination_header_path = destination_subdir + full_filename

        if os.path.isfile("include/" + origin_header_path):
            header_paths["origin"].append(origin_header_path)
            header_paths["destination"].append(destination_header_path)

    return header_paths


def should_check_source_file(file_path, origin_header_paths):
    def needs_includes_updated():
        with open(file_path, "r") as file:
            for line in file:
                for origin_header_path in origin_header_paths:
                    if origin_header_path in line:
                        return True

        return False

    return len(origin_header_paths) > 0 and needs_includes_updated()


def update_includes(filename, origin_subdir, destination_subdir):
    header_paths = get_header_paths(filename, origin_subdir, destination_subdir)

    def for_each_source_file(file_cb):
        for root_dir in __ROOT_DIR_EXTENSIONS:
            for root, subdirs, full_filenames in os.walk(root_dir):
                for full_filename in full_filenames:
                    file_cb(os.path.join(root, full_filename))

    def updated_line(line):
        updated_line = line

        for i in range(len(header_paths["origin"])):
            origin_header_path = header_paths["origin"][i]
            destination_header_path = header_paths["destination"][i]

            if origin_header_path in line:
                updated_line = line.replace(origin_header_path, destination_header_path)
                break

        return updated_line

    def check_update_includes(file_path):
        if should_check_source_file(file_path, header_paths["origin"]):
            with fileinput.FileInput(file_path, inplace = True) as file:
                for line in file:
                    print(updated_line(line), end = "")

    for_each_source_file(check_update_includes)


def move_file(full_filename, origin_dir, destination_dir):
    shutil.move(origin_dir + full_filename, destination_dir + full_filename)

    print(
        "moved \"" + origin_dir + full_filename +
        "\" -> \"" + destination_dir + full_filename + "\"")


def move_files(filename, origin_subdir, destination_subdir):
    for root_dir, extensions in __ROOT_DIR_EXTENSIONS.items():
        for extension in extensions:
            if os.path.isfile(root_dir + origin_subdir + filename + extension):
                move_file(
                    filename + extension,
                    root_dir + origin_subdir,
                    root_dir + destination_subdir)


def cleanup(origin_subdir):
    for root_dir in __ROOT_DIR_EXTENSIONS:
        for root, subdirs, files in os.walk(root_dir + origin_subdir):
            if not files and not subdirs:
                os.rmdir(root_dir + origin_subdir)



def move(filename, origin_subdir, destination_subdir):
    check_make_destination_dirs(filename, origin_subdir, destination_subdir)

    update_includes(
        filename,
        origin_subdir,
        destination_subdir)

    move_files(
        filename,
        origin_subdir,
        destination_subdir)

    cleanup(origin_subdir)


def is_valid_directory(directory):
    return directory[-1] == "/"


def directify(directory):
    return directory if is_valid_directory(directory) else directory + "/"


if len(sys.argv) == 4:
    move(
        filename           = sys.argv[1],
        origin_subdir      = directify(sys.argv[2]),
        destination_subdir = directify(sys.argv[3]))
else:
    print("usage: filename origin-subdirectory destination-subdirectory")
