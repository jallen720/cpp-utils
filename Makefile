all: lib/libcpp_utils.so bin/test
	@:

import_cpp_utils_libs: 
	@:

obj/src/cpp_utils/file.o: src/cpp_utils/file.cpp src/cpp_utils/file.hpp
	@echo compiling $<
	@mkdir -p obj/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/cpp_utils/test.o: src/cpp_utils/test.cpp src/cpp_utils/test.hpp
	@echo compiling $<
	@mkdir -p obj/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/cpp_utils/errors.o: src/cpp_utils/errors.cpp src/cpp_utils/errors.hpp
	@echo compiling $<
	@mkdir -p obj/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/cpp_utils/validators.o: src/cpp_utils/validators.cpp src/cpp_utils/validators.hpp
	@echo compiling $<
	@mkdir -p obj/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/cpp_utils/yaml.o: src/cpp_utils/yaml.cpp src/cpp_utils/yaml.hpp
	@echo compiling $<
	@mkdir -p obj/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/cpp_utils/string.o: src/cpp_utils/string.cpp src/cpp_utils/string.hpp
	@echo compiling $<
	@mkdir -p obj/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/src/cpp_utils/json.o: src/cpp_utils/json.cpp src/cpp_utils/json.hpp
	@echo compiling $<
	@mkdir -p obj/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -fPIC -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

lib/libcpp_utils.so: obj/src/cpp_utils/file.o obj/src/cpp_utils/test.o obj/src/cpp_utils/errors.o obj/src/cpp_utils/validators.o obj/src/cpp_utils/yaml.o obj/src/cpp_utils/string.o obj/src/cpp_utils/json.o
	@echo linking $@
	@mkdir -p lib
	@g++ -shared $^ -L/home/joel/Desktop/packages/yaml-cpp/build -lyaml-cpp -o $@

bin/lib/libcpp_utils.so: lib/libcpp_utils.so
	@echo 'copying $< -> $@'
	@mkdir -p bin/lib
	@cp lib/libcpp_utils.so bin/lib/libcpp_utils.so

bin/lib/libyaml-cpp.so.0.6: /home/joel/Desktop/packages/yaml-cpp/build/libyaml-cpp.so.0.6
	@echo 'copying $< -> $@'
	@mkdir -p bin/lib
	@cp /home/joel/Desktop/packages/yaml-cpp/build/libyaml-cpp.so.0.6 bin/lib/libyaml-cpp.so.0.6

import_test_libs: bin/lib/libcpp_utils.so bin/lib/libyaml-cpp.so.0.6
	@:

obj/tests/src/cpp_utils/file.o: tests/src/cpp_utils/file.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/type.o: tests/src/cpp_utils/type.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/map.o: tests/src/cpp_utils/map.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/vector.o: tests/src/cpp_utils/vector.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/fn.o: tests/src/cpp_utils/fn.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/yaml.o: tests/src/cpp_utils/yaml.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/string.o: tests/src/cpp_utils/string.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/collection.o: tests/src/cpp_utils/collection.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/cpp_utils/json.o: tests/src/cpp_utils/json.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src/cpp_utils
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

obj/tests/src/main.o: tests/src/main.cpp 
	@echo compiling $<
	@mkdir -p obj/tests/src
	@g++ -std=c++14 -ggdb -Wall -Wextra -pedantic-errors -c -Isrc -I/home/joel/Desktop/packages/yaml-cpp/include $< -o $@

bin/test: obj/tests/src/cpp_utils/file.o obj/tests/src/cpp_utils/type.o obj/tests/src/cpp_utils/map.o obj/tests/src/cpp_utils/vector.o obj/tests/src/cpp_utils/fn.o obj/tests/src/cpp_utils/yaml.o obj/tests/src/cpp_utils/string.o obj/tests/src/cpp_utils/collection.o obj/tests/src/cpp_utils/json.o obj/tests/src/main.o
	@echo linking $@
	@mkdir -p bin
	@g++ $^ -Llib -L/home/joel/Desktop/packages/yaml-cpp/build -lyaml-cpp -lcpp_utils -Wl,-rpath,'$$ORIGIN/lib' -o $@

